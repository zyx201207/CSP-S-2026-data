#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1000005;
ll C,T,n,k;
vector<ll> e[maxn];
bool c[maxn],vis[maxn];
struct node{
    ll x,w,fa;
}q[maxn];
ll h,t;
inline ll read(){
    ll res=0,pos=1;
    char ch=getchar_unlocked();
    while(ch<'0' || '9'<ch){
        if(ch=='-') pos*=-1;
        ch=getchar_unlocked();
    }
    while('0'<=ch && ch<='9'){
        res=res*10+ch-'0';
        ch=getchar_unlocked();
    }
    return res*pos;
}
inline void print(ll x){
    if(x>=10) print(x/10);
    putchar_unlocked('0'+x%10);
}
inline ll dfs(ll x){
    h=0,t=0;
    q[0]={x,0,0};
    while(h<=t){
        node dq=q[h++];
        if(c[dq.x]) return dq.w;
        for(ll y:e[dq.x]){
            if(y==dq.fa) continue;
            q[++t]={y,dq.w+1,dq.x};
        }
    }
    return LLONG_MAX;
}
inline void check(ll x,ll fa){
    vis[x]=1;
    for(ll y:e[x]){
        if(y==fa || !c[y]) continue;
        check(y,x);
    }
}
inline ll sol(ll i,ll num){
    if(i>n) return LLONG_MAX;
    if(num==k){
        ll res=0;
        memset(vis,0,sizeof(vis));
        ll t=0;
        for(ll i=1;i<=n;i++){
            if(c[i] && !vis[i]){
                t++;
                if(t>2) return LLONG_MAX;
                check(i,0);
            }
        }
        for(ll i=1;i<=n;i++){
            res=max(res,dfs(i));
        }
        return res;
    }
    c[i]=1;
    ll res=sol(i+1,num+1);
    c[i]=0;
    res=min(res,sol(i+1,num));
    return res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    C=read(),T=read();
    while(T--){
        n=read(),k=read();
        for(ll i=1;i<=n;i++){
            e[i].clear();
        }
        for(ll i=1;i<n;i++){
            ll u=read(),v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ll ans=sol(1,0);
        if(ans==LLONG_MAX) print(1);
        else print(ans);
        putchar_unlocked('\n');
    }
    return 0;
}
