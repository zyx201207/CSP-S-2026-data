#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],head[N+500],pos,dp[505][505];
struct Node
{
    int v,nxt,w;
}e[40*N];
void add(int u,int v,int w)
{
    e[++pos].v=v;
    e[pos].w=w;
    e[pos].nxt=head[u];
    head[u]=pos;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            add(a,i+m,t),add(i+m,a,t);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int u=1;u<=m;u++)
    {
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v1=e[i].v-m,w1=e[i].w;
            for(int j=head[u];j;j=e[j].nxt)
            {
                int v2=e[j].v-m,w2=e[j].w;
                if(v1==v2) continue;
                dp[v1][v2]=min(dp[v1][v2],w1+w2);
                dp[v2][v1]=dp[v1][v2];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                dp[j][i]=dp[i][j];
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        int ans=1e18;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int v1=e[i].v-m,w1=e[i].w;
            for(int j=head[y];j;j=e[j].nxt)
            {
                int v2=e[j].v-m,w2=e[j].w;
                ans=min(ans,dp[v1][v2]+w1+w2);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}