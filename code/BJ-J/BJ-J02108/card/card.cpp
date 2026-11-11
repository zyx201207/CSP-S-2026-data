#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN1 = 5e3 + 10, MAXN2 = 2e5 + 10, MAXM = 5e3 + 10;

ll n, m;
ll a[MAXN2];
// ll ans[MAXM], bj[MAXM], la[MAXN];
ll ans[MAXM], bj[MAXM];
ll sur1[MAXN1][MAXM];
ll sur2[MAXN2][100];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) scanf("%lld", a + i);

    fill(bj + 1, bj + n + 1, -1);
    // for(ll i = 1; i <= n; i++){
    //     if(bj[a[i]] != -1){
    //         la[i] = bj[a[i]];
    //     }
    //     else{
    //         // if(i < n) la[i] = i + 1;
    //         la[i] = -1;
    //     }
    //     bj[a[i]] = i;
    // }

    // for(ll i = n; i >= 1; i--){
        
    // }
    // sur[i][j]
    if(n <= 5000 && m <= 3000){
        bj[a[n]] = n;
        sur1[n][a[n]] = true;
        ans[a[n]]++;
        for(ll i = n - 1; i >= 0; i--){
            // printf("%lld %lld\n", i, bj[a[i]]);
            if(bj[a[i]] != -1){
                for(ll j = 1; j <= m; j++){
                    if(j != a[i]){
                        if(sur1[bj[a[i]]][j]){
                            sur1[i][j] = true;
                            ans[j]++;
                        }
                    }
                    else{
                        sur1[i][j] = true;
                        ans[j]++;                   
                    }
                }
            }
            else{
                for(ll j = 1; j <= m; j++){
                    if(j != a[i]) sur1[i][j] = sur1[i + 1][j];
                    else sur1[i][j] = true;
                    ans[j] += sur1[i][j];
                }
            }
            bj[a[i]] = i;
        }
    }
    else{
        bj[a[n]] = n;
        sur2[n][a[n]] = true;
        ans[a[n]]++;
        for(ll i = n - 1; i >= 0; i--){
            // printf("%lld %lld\n", i, bj[a[i]]);
            if(bj[a[i]] != -1){
                for(ll j = 1; j <= m; j++){
                    if(j != a[i]){
                        if(sur2[bj[a[i]]][j]){
                            sur2[i][j] = true;
                            ans[j]++;
                        }
                    }
                    else{
                        sur2[i][j] = true;
                        ans[j]++;                   
                    }
                }
            }
            else{
                for(ll j = 1; j <= m; j++){
                    if(j != a[i]) sur2[i][j] = sur2[i + 1][j];
                    else sur2[i][j] = true;
                    ans[j] += sur2[i][j];
                }
            }
            bj[a[i]] = i;
        }
    }

    for(ll i = 1; i <= m; i++) 
        printf("%lld ", ans[i]);
    return 0;
}