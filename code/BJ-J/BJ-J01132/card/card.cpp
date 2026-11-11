#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool tong[300005];
ll n, m, a[500005], ans[500005];
stack <ll> z;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!z.empty())
        {
            z.pop();
        }
        memset(tong, 0, sizeof(tong));
        z.push(a[i]);
        tong[a[i]]=1;
        for (int j = i+1; j <= n; j++)
        {
            if (tong[a[j]])
            {
                while (z.top()!=a[j])
                {
                    z.pop();
                }
            }
            else
            {
                tong[a[j]]=1;
                z.push(a[j]);
            }
        }
        while (!z.empty())
        {
            ans[z.top()]++;
            z.pop();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
