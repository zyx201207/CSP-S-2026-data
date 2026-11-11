#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,ans;
int x[2000005],cnt[2000005],mind[2000005];
void dfs(int u,int dis)
{
    if(dis>mind[u]) return;
    for(int v=n;v>u;v--)
    {
        if(x[v]-x[u]>d) continue;
        if(dis+1<mind[v])
        {
            mind[v]=dis+1;
            cnt[v]=0;
        }
        if(dis+1==mind[v]) cnt[v]++;
        dfs(v,dis+1);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cnt[j]=0;
                mind[j]=4e18;
            }
            dfs(i,0);
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
