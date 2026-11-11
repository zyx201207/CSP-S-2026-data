#include <bits/stdc++.h>
using namespace std;
int toint(string s)
{
    int ans = 0;
    for (int i = 0 ; i < s.size(); i++)
    {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
bool check1(char x, char y)
{
    if ((x == 'A') || (x == 'B') || (x == 'C') && (y == 'A') || (y == 'B') || (y == 'C')) return 1;
    else if ((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) return 1;
    else return 0;
}
bool check2(char x, char y)
{
    if (x == 'A' && y == 'B') return 1;
    else if (x == 'B' && y == 'C') return 1;
    else if (x == 'D' && y == 'F') return 1;
    else return 0;
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b, c, d; string x, y, x1, y1; char aa, bb;
    cin >> a >> x >> b >> y;
    x1 = y1 = "";
    x1 += x[0]; x1 += x[1];
    y1 += y[0]; y1 += y[1];
    aa = x[2], bb = y[2];
    c = toint(x1);
    d = toint(y1);
    if (a == b) cout << 1;
    else cout << 0;
    if (a == b && c == d) cout << 1;
    else cout << 0;
    if ((a == b && c == d) && check1(aa, bb)) cout << 1;
    else cout << 0;
    if ((a == b && c == d) && check1(aa, bb) && check2(aa, bb)) cout << 1;
    else cout << 0;
    return 0;
}
