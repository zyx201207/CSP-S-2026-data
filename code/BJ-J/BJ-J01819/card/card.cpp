#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[5001];
int cnt[3001];
int ans[3001];
bool vis[5001];
signed main()
{
    //freopen("card2.in","r",stdin);
    //freopen("card2.out","w",stdout);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            cnt[a[j]]++;
            vis[j] = 1;
            if(cnt[a[j]] != 0)
            {
                for(int k = j - 1;k >= i;k--)
                {
                    if(vis[k])
                    {
                        cnt[a[k]]--;
                        vis[k] = 0;
                        if(a[k] == a[j])
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(int j = 1;j <= m;j++)
        {
            //cout << cnt[j] << " ";
            ans[j] += (cnt[j] != 0);
        }
        //cout << "\n";
        memset(cnt,0,sizeof(cnt));
    }
    for(int j = 1;j <= m;j++)
    {
        cout << ans[j] << " ";
    }
    return 0;
}
