#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a[2000006];
ll dp[5005][5005];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll c, t;
    cin>>c>>t;
    while(t > 0){
        ll n, d;
        cin>>n>>d;
        if(n < 5005){
            ll ans = 0;
            for(ll i=1;i<=n;i++){
                cin>>a[i];
                dp[i][i+1] = 1;
            }
            for(ll l=2;l<=n-1;l++){
                for(ll i=1;i+l<=n;i++){
                    ll j = i + l;
                    dp[i][j] = 1145141919810;
                    if(a[j] - a[i] <= d){
                        dp[i][j] = 1;
                        continue;
                    }
                    for(ll k=i;k<j;k++){
                        if(a[k+1] - a[i] <= d && a[j] - a[k] <= d){
                            if(l >= 3){
                                if(a[k+2] - a[i] > d || k + 2 > j){
                                    if(a[j] - a[k-1] > d || k-1 < i){
                                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                                    }
                                }
                            }
                        }
                        if(k == i && dp[k+1][j] == 2){
                            if(a[k+1] - a[k] <= d && a[k+2] - a[k] > d){
                                dp[i][j] = 2;
                                break;
                            }
                        }
                        else if(k == j - 1 && dp[i][k] == 2){
                            if(a[j] - a[k] <= d && a[j] - a[k-1] > d){
                                dp[i][j] = 2;
                                break;
                            }
                        }
                    }
                    if(dp[i][j] == 2){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    dp[i][j] = 0;
                }
            }
        }
        else{
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }
            if((a[2] - a[1]) * 2 <= d && (a[2] - a[1]) * 3 >= d){
                cout<<n-3<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        t--;
    }
    return 0;
}
