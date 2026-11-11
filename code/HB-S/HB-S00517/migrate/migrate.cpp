#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f;
int n,d;
int x[5005];
vector<int> mp[5005];
int low[5005][5005],cnt[5005][5005];
int vis[5005];
void bzdjs(int u,int dep,int rt)
{
    low[u][u]=0;
    cnt[u][u]=1;
    for(auto v:mp[u])
    {
        for(int i=1;i<=n;i++)
        {
            if(low[v][i]+dep+1<low[rt][i])
            {
                low[rt][i]=low[v][i]+dep+1;
                cnt[rt][i]=cnt[v][i];
            }
            else cnt[rt][i]+=cnt[v][i];
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i],mp[i].clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                low[i][j]=INF;
                cnt[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            for(int j=i+1;j<=r;j++) mp[i].push_back(j);
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(auto v:mp[i]) cout<<v<<" ";
        //     cout<<"\n";
        // }
        // cout<<"---------------------\n";
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            bzdjs(i,0,i);
            for(int j=i;j<=n;j++)
            {
                if(cnt[i][j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}