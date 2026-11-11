#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const ll N=2e6,M=5000;
ll x[N+5];
ll dp[M+5][M+5],cnt[M+5][M+5],mp[M+5];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,T;
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<=5000){
            for(ll u=1;u<=n;u++){
                for(ll v=u;v<=n;v++) dp[u][v]=-1,cnt[u][v]=0,mp[v-u]=0;
                deque<ll> dq;
                dp[u][u]=0;
                cnt[u][u]=1;
                mp[0]=1;
                dq.push_back(u);
                for(ll v=u+1;v<=n;v++){
                    while(!dq.empty()&&x[v]-x[dq.front()]>d) mp[dp[u][dq.front()]]-=cnt[u][dq.front()],dq.pop_front();
                    if(!dq.empty()){
                        dp[u][v]=dp[u][dq.front()]+1;
                        cnt[u][v]+=mp[dp[u][dq.front()]];
                    }
                    if(dp[u][v]==-1) continue;
                    while(!dq.empty()&&dp[u][dq.back()]>dp[u][v]) mp[dp[u][dq.back()]]-=cnt[u][dq.back()],dq.pop_back();
                    dq.push_back(v);
                    mp[dp[u][v]]+=cnt[u][v];
                }
            }
            ll ans=0;
            for(ll i=1;i<=n;i++){
                for(ll j=i+1;j<=n;j++){
                    if(cnt[i][j]==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
