#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
signed main()
{
    File("travel");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
    int car1 = (c1[0] - '0') * 10 + c1[1] - '0', car2 = (c2[0] - '0') * 10 + c2[1] - '0';
    if (car1 != car2)
    {
        cout << "0000";
        return 0;
    }
    cout << "1";
    int row1 = (s1[0] - '0') * 10 + s1[1] - '0', row2 = (s2[0] - '0') * 10 + s2[1] - '0';
    if (row1 != row2)
    {
        cout << "000";
        return 0;
    }
    cout << "1";
    int tmp1 = s1[2] - 'A' + 1, tmp2 = s2[2] - 'A' + 1;
    if (tmp1 > tmp2) swap(tmp1, tmp2);
    if (tmp2 > 3 && tmp1 <= 3)
    {
        cout << "00";
        return 0;
    }
    cout << "1";
    if ((tmp1 == 4 && tmp2 == 6) || tmp2 - tmp1 == 1) cout << "1";
    else cout << "0";
    return 0;
}