#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll maxn=2e5+5;
ll n,m,a[maxn],ans,dp[2][maxn][2];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(ll mask=0;mask<(1<<n);mask++){
            vector<ll> v;
            stack<ll> s;
            ll p=mask,x=0,y=0,cnt=0;
            bool f=0;
            while(p>0){
                s.push(p%2);
                if(p%2==1){
                    x++;
                }p/=2;y++;
            }while(y--){
                v.pb(0);
            }
            while(!s.empty()){
                v.pb(s.top());
                s.pop();
            }
            if(x!=m){
                continue;
            }
            for(ll i=1;i<=n;i++){
                if(v[i-1]==1){
                    if(f==0){
                        cnt=a[i];
                        f=1;
                    }else{
                        cnt&=a[i];
                    }
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<"\n";
    }else{
     /*   dp[0][0][0]=dp[1][0][0]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[0][j][0]=max(dp[1][j][0],dp[1][j-1][1]);
                dp[0][j][1]=max(dp[1][j-1][0],dp[1][j-2][1])&a[j];
            }memcpy(dp[1],dp[0],sizeof dp[0]);
        }
        cout<<max(dp[0][m][0],dp[0][m][1])<<"\n";*/
        sort(a+1,a+n+1,cmp);
        ll cnt=a[1];
        for(ll i=2;i<=m;i++){
            cnt&=a[i];
        }cout<<cnt;
    }
    return 0;
}
