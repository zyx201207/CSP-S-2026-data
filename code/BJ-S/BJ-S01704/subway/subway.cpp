#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[505][500005],ans,k[505],U,V,vis[505][500005];
queue<int> Q,P;
int bfs(int o,int u,int v)
{
    for(int i=1;i<=n;i++){
        if(t[i][u]&&vis[i][u]==0)
        {
            Q.push(i);
            P.push(u);
            vis[i][u]=1;
        }
    }
    while(!Q.empty())
    {
        int p=Q.front(),pp=P.front();
        Q.pop();
        P.pop();
        if(p!=o)
        {
            ans=(ans+t[p][pp]);
            o=p;
        }
        if(t[p][v]){
            return ans+t[p][v];
        }
        bfs(o,pp,v);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int X,Y;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>X>>Y;
            t[i][X]=Y;
        }
    }
    for(int i=1;i<=q;i++){
        ans=0;
        cin>>U>>V;
        ans+=w[U]+w[V];
        bfs(0,U,V);
        cout<<ans<<endl;
    }
    return 0;
}
