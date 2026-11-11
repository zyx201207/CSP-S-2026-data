#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    string r, w;
    cin >> a >> r >> b >> w;
    if (a != b)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    string v, k;
    v = r[0] + r[1];
    k = w[0] + w[1];
    if (v != k)
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    char p, q;
    p = r[2];
    q = w[2];
    if (p == 'A' || p == 'B' || p == 'C')
    {
        if (q == 'A' || q == 'B' || q == 'C')
        {
            cout << 1;
            if (p == 'A' && q == 'C')
                cout << 0;
            else if (p == 'C' && q == 'A')
                cout << 0;
            else
                cout << 1;
        }
        else
            cout << "00";
    }
    else if (p == 'D' && q == 'F')
        cout << "11";
    else
        cout << "00";
}
