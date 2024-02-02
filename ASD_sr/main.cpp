#include <iostream>
using namespace std;
//bool PrimeNum(int n);
#include <cmath>
/*Кавердій Карина 126-23-1
 *Задача 1. Степенем  симетрії  натурального  числа  називають кількість  пар  його десяткових цифр,
 *у яких цифри співпадають і розташовані симетрично відносно середини десяткового запису цього числа.
 *Якщо деяка цифра стоїть посередині десяткового запису, її теж треба враховувати у парі з нею самою.
 *Знайти степінь симетрії числа N.* */
int DegreeOfSymmetry(int n)//функція для першого завдання
{
    int count = 0;
    if(n<1)// Перевірка
    {
        return 1;
    }
    int len = floor(log10(n)+1);// Знаходження кількість цифр в числі
    int a[len];
    // Створення масиву з цифр
    for (int i = 0; i < len; i++) {
        a[i] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < len / 2; i++)// Розгляд половини масиву
        {
        int j = len - i - 1;// Кінець масиву
        if (a[i] == a[j]) {
            count++;
        }
    }
    return count;
}
/*Дано натуральне число n. Від даного числа відніміть суму цифр цього числа,
 * від  утвореного  числа  знову  віднімітьсуму  цифр  утвореного числа  і  т.  д.
 * Дану  операцію  над  числом виконувати,  поки  утворене число додатне.
 * Порахувати скільки разів буде викона надана операція.*/
int CountSubtractio(int n)// Функція для 2 завдання
{
    if( n<= 0){
        return 0;
    }

    int count = 0;
    while (n > 0) {
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        n = n - sum;
        count++;
    }
    count = count - 1;
    return count;
}
/*
 * "Дзеркально  прості"  числа. Число називають"дзеркально  простим",
 * якщо воно є простим, і простим є число, записане тими ж цифрами у зворотному порядку.
 * Знайти кількість "дзеркальнопростих" чисел на проміжку від a до b.*/
int* MirrorPrimes;
int CountMirrorPrimeNum(int a, int b) {
    int count = 0;
    MirrorPrimes = new int[b - a + 1]; // Динамічна памʼять

    for (int i = a; i <= b; i++) {
        int mirror = 0;
        int n = i;
        bool isPrimeOriginal = false;
        bool isPrimeMirror = false;
        // Перевірка простоти оригінального числа
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrimeOriginal = false;
                break;
            } else {
                isPrimeOriginal = true;
            }
        }
        // Створення та перевірка дзеркального числа
        while (n) {
            mirror = mirror * 10 + n % 10;
            n /= 10;
        }
        for (int j = 2; j * j <= mirror; j++) {
            if (mirror % j == 0) {
                isPrimeMirror = false;
                break;
            } else {
                isPrimeMirror = true;
            }
        }

        // Збільшення лічильника, якщо обидва числа прості
        if (isPrimeOriginal == true && isPrimeMirror == true) {
            MirrorPrimes[count] = i;
            count++;
        }
    }
    return count;
}
/*Знайти  кількість  N-значних  чисел,
 *у  яких  сума  цифр дорівнює  їх добутку. Назвати найменше з чисел для даного N (N < 10).*/
void CountNumSumEqualMulti(int n)
{
    int k = 0, num = 0;
    int maxSum = 9 * n;

    auto checkNum = [&](int num) {
        int p = 1, sum = 0, digit;
        int temp = num;

        while (temp > 0)
        {
            digit = temp % 10;
            if (!digit)
                return false;
            sum += digit;
            p *= digit;
            if (p > maxSum)
                return false;
            temp /= 10;
        }

        return p == sum;
    };

    if (n == 1)
    {
        cout << 10 << " " << 0 << endl;
    }
    else
    {
        int a = pow(10, n - 1);
        int b = pow(10, n);

        for (int i = a; i < b; i++)
        {
            if (checkNum(i))
            {
                k++;
                if (k == 1)
                    num = i;
            }
        }
        cout << k << " " << num << endl;
    }
}
/*
 * Факторіал –це функція, яка дорівнює добутку всіх натуральних чисел від 1 до N(N!=1•2•3•...•N).
 * Обчислити факторіал числа.*/
int Factorial(int n)
{
    if (n <= 0) {
        return 1;
    } else {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
/*
 * Подвійний факторіал–це функція,  яка  дорівнює  добутку  непарних натуральних  чисел  від  1  до N,
 * якщо –непарне  (N!!=1•3•...•N),та добутку  парних  чисел,  якщо Nпарне  (N!!=2•4•6•...•N).
 * Обчислити подвійний факторіал для числа N.*/
int DoubleFactorial(int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        // Якщо n непарне, то подвійний факторіал дорівнює добутку непарних чисел від 1 до n
        int result= 1;
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
        return result;
    } else {
        // Якщо n парне, то подвійний факторіал дорівнює добутку парних чисел від 2 до n
        int result = 2;
        for (int i = 2; i <= n; i += 2) {
            result *= i;
        }
        return result;
    }
}
/*Обчислити   перші Nчисел   Фібоначчі   (числа   Фібоначчі   це послідовність, в якій перші
 *два числа дорівнюють 1, кожне наступнедорівнює сумі двох попередніх: F=1, 1, 2, 3, 5, 8, 13...).*/
int* Fibonacci(int n) {
    int* FibonacciAray = new int[n];
    FibonacciAray[0] = 1;
    FibonacciAray[1] = 1;
    for (int i = 2; i < n; i++) {
        FibonacciAray[i] = FibonacciAray[i - 1] + FibonacciAray[i - 2];
    }
    return FibonacciAray;
}
/*Знайти  НСД (найбільший  спільний  дільник) для  чотирьох  чисел (скористатися алгоритмом Евкліда).*/
int NSD(int a, int b, int c, int d) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    while (c != 0) {
        int temp = c;
        c = a % c;
        a = temp;
    }

    while (d != 0) {
        int temp = d;
        d = a % d;
        a = temp;
    }

    return a;
}
/*Досконале  число –це число,  яке  дорівнює  сумі  своїх  дільників,
 *наприклад  6  ділиться  на  1,  2та  3  та
 *дорівнює  їх  сумі:  6=1+2+3;28=1+2+4+7+14. Знайти досконалі числа в діапазоні від 1 до N.*/
int findAndPrintPerfectNumbers(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= i / 2 + 1; j++) {
            if (i % j == 0) sum += j;
        }

        if (sum == i) {
            cout << i << " ";
            count++;
        }
    }

    return count;
}
/*Задано  натуральне  число  m.  Якщо  це  не  паліндром
 * (паліндром  це число, яке однакове з обох боків –число-перевертень),
 * то записуємо його  у  зворотному  порядку  та  додаємо  до  заданого.
 * Кроки повторюються,  доки  не  буде  отримано  число-паліндром.
 * Кількість виконаних операцій називаютьрівнем паліндромності заданого числа.Знайти рівень паліндромності числа m.
 * */
int LevelPol(int n) {
    int n1, n2;// n1 число в зворотному порядку, n2 - це сума n і n1
    int c;// Тимчасова змінна для зберігання одиниць розряду
    int k = 0; // Кількість

    while (true)// Цикл повторюється до тих пір, поки n не стане паліндромом.
    {
        n1 = n;
        n2 = 0;
        while (n1 > 0) {// Перевертаємо n1
            c = n1 % 10;
            n1 /= 10;
            n2 = n2 * 10 + c;
        }

        if (n == n2) { // Чи є n паліндромом?
            return k;
        } else {
            n += n2; // Нове число
            k++; //+ рівень паліндропа
        }
    }
}
int main() {
    int task;
    int n;
    int count;
    int a, b, c, d;
    cout << "Введіть номер задачі " << endl;
    cin >> task;

    if (task == 1) {
        cout << "Введіть N для завдання 1: " << endl;
        cin >> n;
        count = DegreeOfSymmetry(n);
        cout << "Степінь симетрії: " << count << endl;
    } else if (task == 2) {
        cout << "Введіть N для завдання 2: " << endl;
        cin >> n;
        cout << "Число операцій: " << CountSubtractio(n) << endl;
    } else if (task == 3) {
        cout << "Введіть а: " << endl;
        cin >> a;
        cout << "Введіть b: " << endl;
        cin >> b;
        count = CountMirrorPrimeNum(a, b);
        cout << "Кількість дзеркально простих чисел на проміжку " << count << endl;
        cout << "Прості дзеркальні числа(для перевірки програми): " << endl;
        for (int i = 0; i < count; i++) {
            cout << MirrorPrimes[i] << " "<<endl;
        }
        delete[] MirrorPrimes;
    } else if(task == 4){
        cout << "Введіть n: " << endl;
        cin >> n;
        CountNumSumEqualMulti(n);
    } else if(task == 9)
    {
        cout << "Введіть n: " << endl;
        cin >> n;
        cout<< Factorial(n)<<endl;
    } else if(task == 10)
    {
        cout << "Введіть n: " << endl;
        cin >> n;
        cout<< DoubleFactorial(n)<<endl;

    } else if(task == 8){
        cout << "Введіть n: " << endl;
        cin >> n;
        int* FibonacciAray = Fibonacci(n);
        for (int i = 0; i < n; i++) {
            cout << FibonacciAray[i] << " "<< endl;
        }
        delete[] FibonacciAray;
    } else if(task == 7){
        cout << "Введіть a: " << endl;
        cin >> a;
        cout << "Введіть b: " << endl;
        cin >> b;
        cout << "Введіть c: " << endl;
        cin >> c;
        cout << "Введіть d: " << endl;
        cin >> d;
        cout<<NSD(a,b,c,d)<<endl;
    } else if(task == 6){
        cout << "Введіть n: "<<endl;
        cin >> n;
        cout<<findAndPrintPerfectNumbers(n)<<endl;
    } else if(task == 5)
    {
        cout << "Введіть n: "<<endl;
        cin >> n;
        cout<<LevelPol(n);
    }
    return 0;
}
