#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e6+5;
ll dp[MAXN][2], a[MAXN], c, q, n, d;//第i个树开始，第j个数结束
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &q);
    while(q--){
        ll re=0;
        scanf("%lld %lld", &n, &d);
        for(int i=1;i<=n;i++)scanf("%lld", &a[i]);
        for(int s=1;s<=n;s++){
            memset(dp, 0, sizeof(dp));
            dp[s][0]=1;
            dp[s][1]=0;
            for(int i=s+1;i<=n;i++){
                ll minm=n+1;
                for(int j=i;j>=s;j--){
                    if(a[i]-a[j]>d)break;
                    if(dp[j][1]+1>minm)continue;
                    if(dp[j][1]+1==minm){
                        dp[i][0]+=dp[j][0];
                    }else{
                        dp[i][0]=dp[j][0];
                        dp[i][1]=dp[j][1]+1;
                        minm=dp[j][1]+1;
                    }
                }if(dp[i][0]==2)re++;
            }
            //for(int i=1;i<=n;i++)cout <<dp[i][0] << " " << dp[i][1] << '\n';
            //cout << '\n';
        }printf("%lld\n", re);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}