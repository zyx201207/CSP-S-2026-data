#include<bits/stdc++.h>
using namespace std;
int w[500010],k[510],t[500010][510];
bool g[500010][510];
bool vis[500010][510];
struct node
{
    int nid,xl,val;
    bool operator < (node b)const{
        return val<b.val;
    }
};
int DijFA(int a,int b,int n,int m)
{
    memset(vis,0,sizeof(vis));
    priority_queue<node>q;
    for(int i=1;i<=n;i++)
    {
        q.push({a,i,t[a][i]});
        vis[a][i]=1;
    }
    while(!q.empty())
    {
        node x=q.top();
        q.pop();
        if(x.nid==b)
        {
            return x.val;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[x.nid][i]&&t[x.nid][i]<1061109567){q.push({x.nid,i,x.val+t[x.nid][x.xl]+t[x.nid][i]});vis[x.nid][i]=1;}
        }
        for(int i=1;i<=m;i++)
        {
            if(g[i][x.xl]&&!vis[i][x.xl]){q.push({i,x.xl,x.val}),vis[i][x.xl]=1;}
        }
    }
    return 0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,c,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(t,0x3f,sizeof(t));
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            cin>>x;
            cin>>t[x][i];
            g[x][i]=1;
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int ans=0;
        ans+=w[a]+w[b];
        //cout<<w[a]<<" "<<w[b]<<endl;
        ans+=DijFA(a,b,n,m);
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
