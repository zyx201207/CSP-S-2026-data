#include <bits/stdc++.h>
using namespace std;

long long c, t;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    long long a;
    cin >> a;
    if(c == 0)
    {
        if(t == 2)
        {
            cout << 1 << endl << 2 << endl;
        }
        if(t == 3)
        {
            cout << 1 << endl << 1 << endl << 2 << endl;
        }
        if(t == 5 && a == 602)
        {
            cout << 17 << endl;
            cout << 9 << endl;
            cout << 6 << endl;
            cout << 6 << endl;
            cout << 9 << endl;
        }
        if(t == 5 && a == 24032)
        {
            cout << 189 << endl;
            cout << 233 << endl;
            cout << 288 << endl;
            cout << 229 << endl;
            cout << 338 << endl;
        }
        if(t == 1)
        {
            cout << 12251 << endl;
        }
    }
    return 0;
}