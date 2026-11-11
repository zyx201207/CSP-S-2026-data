#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int c[a];
    for (int i = 1;i <= a;i++)
    {
        cin >> c[i];
        cout << c[i];
    }

    return 0;
}
