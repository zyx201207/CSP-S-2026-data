#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,ans;
vector<ll> vec[1000001];
ll  val[1000001],dep[11],f[11];
void dfs(ll u,ll fa){
    for(auto to:vec[u]){
        if(to==fa) continue;
        dep[to]=min(dep[to],dep[u]+1);
        dfs(to,u);
    }
}
ll cnt=0,x[11];
void ch(ll u,ll v){
    for(auto to:vec[u]){
        if(to==v) continue;
        if(val[u] && val[to]) x[to]=x[u];
        else if(!val[u] && val[to]) x[to]=++cnt;
        ch(to,u);
    }
}
ll checks(){
    cnt=0;
    memset(x,0,sizeof(x));
    if(val[1]) x[1]=++cnt;
    ch(1,1);
    if(cnt>2) return 0;
    return 1;
}
void get(ll u,ll op){
    if(op==k){
        if(!checks()) return ;
        for(int i=1;i<=n;i++) f[i]=2e18;
        for(int i=1;i<=n;i++){
            if(!val[i]) continue;
            for(int j=1;j<=n;j++){
                if(val[j]) dep[j]=0;
                else dep[j]=2e18;
            }
            dfs(i,i);
            for(int j=1;j<=n;j++) f[j]=min(f[j],dep[j]);
        }
        ll now=0;
        for(int i=1;i<=n;i++) now=max(now,f[i]);
        ans=min(ans,now);
        return ;
    }
    if(u==n+1) return ;
    for(int i=0;i<=1;i++){
        if(i==0) val[u]=0,get(u+1,op);
        else{
            val[u]=1;
            get(u+1,op+1);
            val[u]=0;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >>c >>t;
    while(t--){
        cin >>n >>k;
        ans=2e18;
        for(int i=1;i<=n;i++) vec[i].clear();
        for(int i=1;i<n;i++){
            ll u,v;
            cin >>u >>v;
            vec[u].push_back(v);vec[v].push_back(u);
        }
        get(1,0);
        cout <<ans <<'\n';
    }
    return 0;
}
