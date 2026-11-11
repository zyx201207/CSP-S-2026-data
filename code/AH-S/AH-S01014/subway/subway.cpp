#include<bits/extc++.h>
using namespace std;
long long c,n,m,d,Q,ans=1e18,q[500005],use[500005];
vector<vector<long long>> zhan(500005);
void dfs(long long a,long long b,long long t)
{
    if(a==b) {
            ans=min(ans,t);
            return;
    }
    use[a]=1;
    for(int i=0;i<zhan[a].size();i+=2)
    if(use[zhan[a][i]]==0) dfs(zhan[a][i],b,t+zhan[a][i+1]);
    use[a]=0;
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>q[i];
    for(int i=1;i<=n;i++)
    {
        long long k,u,v,t1,t2;
        cin>>k>>u>>t1>>v>>t2;
        if(k==2)
        {
            zhan[u].push_back(v);
            zhan[u].push_back(t1+t2);
        }
    }
    while(Q--)
    {
        int i=0,u,v;
        cin>>u>>v;
        dfs(u,v,0);
        cout<<ans+q[u]+q[v]<<endl;
    }
    return 0;
}
