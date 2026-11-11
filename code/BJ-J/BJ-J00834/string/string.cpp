#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int num[N];
char ch[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        cin >> ch[i];
    }
    int posR = n;
    int ans = 0;
    for (int posL = 1; posL <= n && posL < posR; ++posL)
    {
        int cnt = 0;
        while (true)
        {
            if (num[posR] + cnt >= num[posL])
            {
                num[posR] -= num[posL] - cnt;
                if (ch[posR] != ch[posL]) ans += num[posL] - cnt;
                if (num[posR] == 0) posR--;
                break;
            }
            else
            {
                cnt += num[posR];
                if (ch[posR] != ch[posL]) ans += num[posR];
                posR--;
            }
        }
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
