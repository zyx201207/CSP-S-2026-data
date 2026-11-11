#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,d;
ll x[2000010];
queue<pr> q;
bool bfs(ll u,ll v){
    ll mn=inf,cnt=0;
    while(!q.empty())q.pop();
    q.push({u,0});
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll s=t.first,dis=t.second;
        if(s==v){
            cnt++;
            mn=dis;
            q.pop();
            continue;
        }
        if(cnt){
            if(dis>mn)break;
            else continue;
        }
        for(ll i=1;i<=n;i++){
            if(abs(x[s]-x[i])<=d)
            q.push({i,dis+1});
        }
    }
    if(cnt==2)return 1;
    else return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll C,T;cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++)cin>>x[i];
        ll ans=0;
        for(ll i=1;i<=n-1;i++){
            for(ll j=i+1;j<=n;j++){
                ans+=bfs(i,j);
            }
        }
        cout<<ans<<"\n";
    }
}