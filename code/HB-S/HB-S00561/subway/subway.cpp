#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
inline ll read(){
    ll x=0,f=1;
    int c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
inline void print(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
const int maxn=505,maxm=5e5+5;
vector<pil>sta[maxm];
vector<pil>met[maxn];
int c,n,m,d,q;
ll w[maxn],dis[maxm];
ll subw(int st,int ed){
    priority_queue<pil>q;
    q.push({st,0});
    for(int i=1;i<=m;i++){
        dis[i]=0x3f3f3f3f3f3f3f3f;
    }
    dis[st]=0;
    while(!q.empty()){
        int u=q.top().first;
        ll t=q.top().second;
        q.pop();
        if(t>dis[ed])continue;
        for(auto v:sta[u]){
            ll tv=v.second;
            int vv=v.first;
            for(auto vx:met[vv]){
                int mv=vx.first;
                ll mt=vx.second;
                if(mv==u)continue;
                if(dis[mv]>t+tv+mt){
                    dis[mv]=t+tv+mt;
                    q.push({mv,dis[mv]});
                }
            }
        }
    }
    return dis[ed]+w[st]+w[ed];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=0;j<k;j++){
            int a=read();
            ll t=read();
            met[i].push_back({a,t});
            sta[a].push_back({i,t});
        }
    }
    while(q--){
        int x=read(),y=read();
        ll ans=subw(x,y);
        print(ans);
        puts("");
    }
    return 0;
}