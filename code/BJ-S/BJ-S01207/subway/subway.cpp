#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],x,y,lal[505][505],ans;
bool vis[505];
struct node
{
    int z,t;
};
vector<node> s[505];
void dfs(int a,int b,int re,int t)
{
    if(re==b)
    {
        ans=min(ans,t);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&lal[re][i]!=1e9)
        {
            vis[i]=1;
            dfs(a,b,i,t+lal[re][i]);
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a,ti;
            cin>>a>>ti;
            s[a].push_back({i,ti});
        }
    }
    memset(lal,1e9,sizeof lal);

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=s[i].size()-2;j++)
        {
            for(int k=j+1;k<=s[i].size()-1;k++)
            {
                lal[s[i][j].z][s[i][k].z]=min(lal[s[i][j].z][s[i][k].z],s[i][j].t+s[i][k].t);
                lal[s[i][k].z][s[i][j].z]=lal[s[i][j].z][s[i][k].z];
            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        ans=1e9;
        for(int i=0;i<=s[x].size()-1;i++)
        {
            for(int j=0;j<=s[y].size()-1;j++)
            {
                memset(vis,0,sizeof vis);
                vis[s[x][i].z]=1;
                dfs(s[x][i].z,s[y][j].z,s[x][i].z,w[x]+w[y]+s[x][i].t+s[y][j].t);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
