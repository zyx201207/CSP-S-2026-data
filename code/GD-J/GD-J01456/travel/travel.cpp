#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, t1, t2;
    char a1, a2;
    cin >> c1 >> t1 >> a1 >> c2 >> t2 >> a2;
    if (c1 != c2)
    {
        cout << "0000";
    }
    else
    {
        cout << "1";
        if (t1 != t2)
        {
            cout << "000";
        }
        else
        {
            cout << "1";
            if ((a1 <= 'C' && a2 <= 'C') || (a1 >= 'D' && a2 >= 'D'))
                cout << "1";
            else
                cout << "0";
            if ((char(a1 + 1) == a2 && a1 != 'C') || (char(a2 + 1) == a1 && a2 != 'C'))
                cout << "1";
            else
                cout << "0";
        }
    }
    return 0;
}
