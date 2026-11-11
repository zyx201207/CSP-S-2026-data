#include<bits/stdc++.h>
using namespace std;
int n, m,cnt[300005], p[500005], s[300005];
bool vis[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >>n >> m;
    int maxn1 = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> p[i];
        maxn1 = max(maxn1, p[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        int maxn = 0;
        for(int j = i;j <= n;j++)
        {
            if(vis[p[j]])
            {
                for(int k = j - 1;k >= i;k--)
                {
                    if(p[k] == p[j])
                    {
                        break;
                    }
                    vis[p[k]] = 0;
                }
                for(int k = 1;k <= maxn1;k++)
                {
                    cnt[k] += int(vis[k]);
                }
                for(int k = 1;k <= maxn1;k++)
                {
                    vis[k] = 0;
                }
                break;
            }
            else
                vis[p[j]]++;
                maxn = max(maxn, p[j]);
        }

    }
    for(int i = 1;i <= maxn1;i++)
    {
        cout << cnt[i]<< " ";
    }

    return 0;
}
