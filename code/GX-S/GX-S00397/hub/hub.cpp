#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+1;
struct trees{
    int to,nxt;
}t[N];
int head[N],dep[N];
int cnt,n,k,c,T,mxdp;
void add(int u,int v){
    t[++cnt].to = v;
    t[cnt].nxt = head[u];
    head[u] = cnt;
}
void init(){
    memset(head,-1,sizeof(head));
    memset(dep,0,sizeof(dep));
    cnt = 0;
    for(int i=1;i<=2*n;i++){
        t[i].to = t[i].nxt = 0;
    }
}
void dfs(int x,int fa){
    dep[x] = dep[fa]+1;
    mxdp = max(mxdp,dep[x]);
    for(int i=head[x];i!=-1;i=t[i].nxt){
        int v = t[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);add(v,u);
        }
        int root = 1;
        dfs(root,0);
        for(int i=1;i<=n;i++){
            if(dep[i] == mxdp){
                root = i;
                break;
            }
        }
        mxdp = 0;
        dfs(root,0);
        cout<<mxdp/k<<"\n";
    }
    return 0;
}
