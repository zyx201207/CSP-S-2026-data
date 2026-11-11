#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 2000005
int n,d;
int x[MAXN];
int steps[MAXN],counts[MAXN];
int zuo[MAXN],you[MAXN];
int dp[MAXN];
vector<int> fen;
void solve2(){
    scanf("%lld%lld",&n,&d);
    for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
    int ex = d % (x[2] - x[1]);
    if(2 * ex >= (x[2] - x[1]))  printf("0\n");
    else{
        int ans = 0;
        int tmp = d / (x[2] - x[1]);
        if(tmp <= 1) printf("0\n");
        else printf("%lld\n",max((long long)0,n - (2 * tmp - 1)));
    }
}
void solve3(){
    scanf("%lld%lld",&n,&d);
    for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
    for(int i = 1; i <= n; i++) you[i] = upper_bound(x+1,x+n+1,x[i] + d) - (x+1);
    for(int i = 1; i <= n; i++) zuo[i] = lower_bound(x+1,x+n+1,x[i] - d) - x;
    int ans = 0;
    for(int l = 1; l <= n; l++){
        fen.clear(); int j;
        for(j = l; j <= n; ){
            fen.push_back(j);
            if(you[j] == j) break;
            else j = you[j];
        }
        if(j > n && fen[fen.size()-1] != n) fen.push_back(n);
        dp[l] = 1;
         for(int j = 1; j < fen.size(); j++){
             int zhi = fen[j];
             int x = zuo[zhi],y = fen[j-1];
             x = max(x,l);
             if(y-x >= 2) break;
             if(y-x == 1){
                 if(dp[x] + dp[y] > 2) break;
                 else dp[zhi] = dp[x] + dp[y];
             }
             if(y-x == 0){
                 dp[zhi] = dp[x];
             }
             if(fen[j] - fen[j-1] == 1 && j != fen.size() - 1){
                 if(dp[zhi] == 2) ans = ans + (fen[j+1] - fen[j]);
             }
             if(fen[j] - fen[j-1] == 1) continue;
             x = zuo[zhi-1];
            x = max(x,l);
             if(y-x >= 2) dp[zhi-1] = 3;
             if(y-x == 1){
                 dp[zhi-1] = min((long long)3,dp[x]+dp[y]);
             }
             if(y-x ==0){
                 dp[zhi-1] = dp[x];                
             }
             if(fen[j] - fen[j-1] == 2){
                 int you1 = you[fen[j]],you2 = you[fen[j]-1];
                 if(dp[zhi] == 2) ans = ans + (you1 - you2);
                 else if(dp[zhi] + dp[zhi-1] == 2) ans = ans + (you2 - fen[j]);
             }else{
                 int you1 = you[fen[j]],you2 = you[fen[j]-1],you3 = you[fen[j] - 2];
                 if(dp[zhi] == 2) ans = ans + (you1 - you2);
                 else if(dp[zhi] + dp[zhi-1] == 2) ans = ans + (you2 - you3);
             }

         }
    }
    printf("%lld\n",ans);
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T; scanf("%lld%lld",&C,&T);
    if(C >= 11 && C <= 12) while(T--) solve2();
    else while(T--) solve3();
    return 0;
}