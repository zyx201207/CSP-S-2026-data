#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[500005];
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i],vis[i] = 1;
    for(int v = 29; v >= 0; v--)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(((a[i] >> v) & 1) && vis[i]) cnt++;
        }
        if(cnt >= m) 
        {
            ans += (1ll << v);
            for(int i = 1; i <= n; i++)
            {
                if((((a[i] >> v) & 1) ^ 1) && vis[i]) vis[i] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
