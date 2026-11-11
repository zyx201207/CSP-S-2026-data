#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll rd(){
    char ch=getchar();
    ll f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
ll ans,N,Q,K,C,T;
struct Node{
    ll u,v;
}edge[1000000];
ll dis[100000];
vector<ll> q[10000];
inline void work(){
    ans=1e12;
    N=rd();K=rd();
    for(int i=1;i<=N;i++)q[i].clear();
    for(int i=1;i<N;i++){
        ll u=rd(),v=rd();
        edge[i]={u,v};
        q[u].push_back(i);
        q[v].push_back(i);
    }
    for(int i=1;i<1<<N;i++){
        if(__builtin_popcount(i)!=K)continue;
        ll cnt=0;
        for(int j=1;j<N;j++){
            ll u=edge[i].u,v=edge[i].v;
            if(i>>(u-1)&1&&i>>(v-1)&1)cnt++;
        }
        if(cnt!=K-1)continue;
        queue<ll> p;p.clear();
        mesmet(dis,0x3f,sizeof(dis));
        for(int j=0;j<N;j++){
            if(i>>j&1)dis[j+1]=0,p.push(j+1);
        }
        while(!p.empty()){
            ll u=p.front();
            p.pop();
            for(auto k:q[u]){
                ll v=edge[k].u+edge[k].v-u;
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    p.push(v);
                }
            }
        }
        ll mx=0;
        for(int j=1;j<=N;j++)mx=max(mx,dis[j]);
        ans=min(ans,mx);
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    C=rd();T=rd();
    while(T--){
        work();
        clear();
    }
    return 0;
}