#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+6;
ll c,t,n,d,x[N],col[N],h[N];
bool vis[N];
void bfs(ll s){
    queue<pair<ll,ll>>q;
    memset(col,0,sizeof col);
    memset(h,0,sizeof h);
    q.push({s,0});
    while(q.size()){
        ll u=q.front().first,cnt=q.front().second;q.pop();
        if(col[u]!=0&&col[u]<cnt)continue;
        col[u]=cnt;h[u]++;
        for(ll i=1;i<=n;i++){
            //can use lower_bound to opt
            if(abs(x[u]-x[i])<=d){
                q.push({i,cnt+1});
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++)cin>>x[i];
        ll ans=0;
        for(ll i=1;i<=n;i++){
            bfs(i);
            for(ll j=1;j<=n;j++){
                if(i!=j)ans+=(h[j]==2);
            }
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}