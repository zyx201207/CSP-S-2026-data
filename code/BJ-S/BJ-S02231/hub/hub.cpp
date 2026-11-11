#include<bits/stdc++.h>
#define ll long long
#define MAXN 2000005
#define inf 0x3f3f3f3f
using namespace std;
vector<ll>c[MAXN];
ll n,m,dp[MAXN],a[MAXN],C,f[MAXN],xx,yy,la,cnt;
void dfs(ll x){
    for(auto i:c[x])
        if(!f[i]){
            f[i]=1;
            la++;
            dfs(i);
            la--;
            f[i]=0;
        }
    if(la>cnt)
        cnt=la,xx=x;
}
void solve(){
    cin>>n>>m;
    ll jk=n-1;
    while(jk--){
        ll u,v;
        cin>>u>>v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    f[1]=1;
    dfs(1);
    f[1]=0;
    yy=xx;
    f[yy]=1;
    dfs(yy);
    f[yy]=0;
    cnt++;
    bool ff=(cnt-m)%3;
    ll ans=(cnt-m)/3+ff;
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)
        c[i].clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    //t=1;
    cin>>C>>t;
    while(t--)
        solve();
    return 0;
}
