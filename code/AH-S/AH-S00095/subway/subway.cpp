#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
using ll=__int128;
ll read(){
    ll f=1,x=0;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-')f=1-f;
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^48);
        cc=getchar();
    }while(isdigit(cc));
    return(f?x:-x);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=read(),n=read(),m=read(),d=read(),q=read();
    vector<vector<array<int,2>>>g(n+m+5);
    vector<int>w(m);
    fo(i,1,m)w[i]=read();
    fo(i,1,n){
        int k=read();
        fo(j,1,k){
            int u=read(),wg=read();
            g[i+m].push_back({u,wg});
            g[u].push_back({i+m,wg});
        }
    }
    //for(int i=1;i<=n+m;++i){
    //    for(auto&[v,w]:g[i]){
    //        printf("%d %d %d\n",i,v,w);
    //    }
    //}
    vector<bool>calc(m+5);
    vector<vector<ll>>dist(m+5);
    while(q--){
        int u=read(),v=read();
        if(!calc[u]){
            vector<ll>dst(n+m+5,0x3f3f3f3f3f3f3f3f);
            dst[u]=0;
            priority_queue<array<ll,2>,vector<array<ll,2>>,less<array<ll,2>>>q;
            q.push({0,u});
            while(!q.empty()){
                auto[Dst,u]=q.top();
                q.pop();
                if(Dst!=dst[u])continue;
                for(auto&[v,w]:g[u]){
                    if(dst[v]>dst[u]+w){
                        dst[v]=dst[u]+w;
                        q.push({dst[v],v});
                    }
                }
            }
            dist[u]=dst;
        }
        printf("%lld\n",dist[u][v]+w[u]+w[v]);
    }
    return 0;
}
