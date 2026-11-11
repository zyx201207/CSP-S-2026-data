#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

string a, b, c, d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if (a != c)
    {
        cout << "0000";
        return 0;
    }
    cout << '1';
    if (b[0] != d[0] || b[1] != d[1])
    {
        cout << "000";
        return 0;
    }
    cout << '1';
    if ((b[2] <= 'C' && d[2] >= 'D') || (b[2] >= 'D' && d[2] <= 'C'))
    {
        cout << "00";
        return 0;
    }
    cout << '1';
    if (b[2] - d[2] != 1 && d[2] - b[2] != 1)
    {
        cout << "0";
        return 0;
    }
    cout << '1';
    return 0;
}
