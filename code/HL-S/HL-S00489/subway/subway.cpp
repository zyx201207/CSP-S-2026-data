#include<bits/stdc++.h>
using namespace std;
int vis[1005],dis[1005],_[100005][25],_1[100005],c,n,m,d,q,w[100005],k[100005],a[1005][1005],t[1005][1005],x,y;
int bfs(int a1,int b)
{
    queue<int>q;
    q.push(a1);
    dis[a1]=w[a1]+t[a1][a1];
    vis[a1]=1;
    while(!q.empty())
    {
        int f=q.front();
        if(f==b)return dis[f]+w[f]-t[f][f];
        q.pop();
        for(int j=1;j<=_1[f];j++)
        {
            for(int i=1;i<=k[_[f][j]];i++)
            {
                int s1=a[_[f][j]][i];
                if(!vis[s1])
                {
                    vis[s1]=1;
                    q.push(s1);
                    dis[s1]=dis[f]+t[f][s1]+t[s1][s1];
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++){cin>>a[i][j]>>t[i][j];_[a[i][j]][++_1[a[i][j]]]=i;}
    }
    for(int r=1;r<=q;r++)
    {
        cin>>x>>y;
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        cout<<bfs(x,y)<<endl;
    }
    return 0;
}
