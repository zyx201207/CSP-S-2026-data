#include <iostream>
using namespace std;
struct Edge{
    int n,v,w;
};

Edge edge[10000000];
int l,head[1000000];
bool b[1000000];
int c,n,m,d,q;
int st,to,mx=2.1e9;

void add(int u,int v,int w)
{
    l++;
    edge[l].w=w;
    edge[l].v=v;
    edge[l].n=head[u];
    head[u]=l;
}

void dfs(int n,int cos)
{
    if(n==to)
    {
        if(cos<mx)
        {
            mx=cos;
            return;
        }
    }
    if(cos>=mx)
    {
        return;
    }
    for(Edge i=edge[head[n]];i.v!=0;i=edge[i.n])
    {
        if(!b[i.v])
        {
            b[i.v]=1;
            dfs(i.v,cos+i.w);
            b[i.v]=0;
        }
    }
}

int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        add(i,i+m,t);
        add(i+m,i,t);
    }
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            int x,y;
            cin>>x>>y;
            add(x+m,i+m+2*m,y);
            add(i+m+2*m,x+m,y);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>st>>to;
        b[st]=1;
        dfs(st,0);
        cout<<mx<<endl;
        mx=2.1e9;
        b[st]=0;
    }

    return 0;

}
