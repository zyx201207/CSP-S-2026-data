#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a, b, c, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d;

    if (a == c)
        cout << 1;
    else
        return cout << "0000" << endl, 0;

    if (b[0] == d[0] && b[1] == d[1])
        cout << 1;
    else
        return cout << "000" << endl, 0;

    if ((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C'))
    {
        cout << 1;
        if ((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A'))
            cout << 1 << endl;
        else if ((b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A'))
            cout << 0 << endl;
        else if ((b[2] == 'C' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C'))
            cout << 1 << endl;
    }
    else if ((b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F'))
        return cout << "11" << endl, 0;
    else
        return cout << "00" << endl, 0;
    return 0;
}
