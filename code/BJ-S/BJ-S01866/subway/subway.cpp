#include<bits/stdc++.h>
using namespace std;
struct node
{
    int to;
    long long dis;
    bool friend operator < (node x,node y)
    {
        return x.dis>y.dis;
    }
};
const int N=505,M=5e5+5;
const long long oo=1e18;
int c,n,m,d,q,w[M],tot[M],pre[M][21];
long long pret[M][21],mp[N][N],dis[N][N],ans;
bool ss[N];
priority_queue<node>que;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            mp[i][j]=oo;
            mp[j][i]=oo;
        }
    }
    for(int i=1,k,a,t;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            for(int l=1;l<=tot[a];l++)
            {
                mp[pre[a][l]][i]=min(mp[pre[a][l]][i],pret[a][l]+t);
                mp[i][pre[a][l]]=mp[pre[a][l]][i];
            }
            ++tot[a];
            pre[a][tot[a]]=i;
            pret[a][tot[a]]=t;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dis[i][j]=oo;
            ss[j]=0;
        }
        ss[i]=0;
        que.push(node{i,0});
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<i;k++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        while(!que.empty())
        {
            node top=que.top();
            que.pop();
            if(ss[top.to])
            {
                continue;
            }
            ss[top.to]=1;
            for(int j=i+1;j<=n;j++)
            {
                if(j==top.to)
                {
                    continue;
                }
                if(dis[i][top.to]+mp[top.to][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][top.to]+mp[top.to][j];
                    que.push(node{j,dis[i][j]});
                }
            }
        }
        for(int j=i+1;j<=n;j++)
        {
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1,x,y;i<=q;i++)
    {
        cin>>x>>y;
        ans=oo;
        for(int j=1;j<=tot[x];j++)
        {
            for(int l=1;l<=tot[y];l++)
            {
                ans=min(ans,pret[x][j]+pret[y][l]+dis[pre[x][j]][pre[y][l]]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}