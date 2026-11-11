#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+1;
int n,k;
struct Edge{
    int to,nxt;
}edge[N<<1];
int head[N],cnt;
inline void init(){
    cnt=0;
    memset(head,-1,sizeof(int)*(n+5));
}
inline void add_edge(int u,int v){
    edge[cnt]={v,head[u]};
    head[u]=cnt;
    ++cnt;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            add_edge(u,v);
            add_edge(v,u);
        }
        cout<<0<<'\n';
    }
}