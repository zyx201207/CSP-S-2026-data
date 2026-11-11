#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,head[1000005],cnt,dep[1000005],res;
struct node{
    int nxt,to;
}e[1000005];
inline void add(int u,int v)
{
    e[++cnt]={head[u],v},head[u]=cnt;
    e[++cnt]={head[v],u},head[v]=cnt;
}
inline int dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    int mx=dep[u];
    for(int i=head[u],v;i;i=e[i].nxt)
    {
        v=e[i].to;
        if(v!=fa) {
            int o=dfs(v,u);
            if(o>=mx)
            {
                res=max(res,mx-dep[u]+o-dep[u]);
                mx=o;
                // cout<<res<<" ";
            }
        }
    }
    // cout<<dep[u]<<" ";
    return mx;
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(head,0,sizeof head);
        memset(dep,0,sizeof dep);
        cnt=res=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
        }
        // cout<<t<<" "<<n<<" "<<cnt<<"\n";
        if(k<=2)
        {
            dfs(1,0);
            cout<<(res+2)/4<<"\n";
        }
    }


    return 0;
}