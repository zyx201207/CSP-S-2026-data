#include<bits/stdc++.h>
using namespace std;

using LL=long long ;

int c,t,n,k;

int head[1000],cnt;
struct E{int next,to}G[10100];
void add(int u,int v){
    G[++cnt]={head[u],v};head[u]=cnt;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }

        cout<<!(k==n)<<'\n';
    }

    return 0;
}

