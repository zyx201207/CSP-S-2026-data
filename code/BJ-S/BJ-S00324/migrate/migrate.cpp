#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long x[N];
int dp[N],cnt[N],q[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        long long d,ans = 0;
        scanf("%d%lld",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                dp[j] = 2e6 + 10;
                cnt[j] = 0;
            }
            dp[i] = 0;
            cnt[i] = 1;
            int head = 1,tail = 0;
            q[++tail] = i;
            for(int j = i + 1;j <= n;j++){
                while(head <= tail && x[j] - x[q[head]] > d){
                    head++;
                }
                if(head <= tail){
                    dp[j] = dp[q[head]] + 1;
                    cnt[j] = cnt[q[head]];
                }
                int k = 1;
                while(head + k <= tail && dp[q[head + k]] + 1 == dp[j] && cnt[j] <= 2){
                    cnt[j] += cnt[q[head + k]];
                    k++;
                }
                if(cnt[j] > 2){
                    cnt[j] = 3;
                }
                if(cnt[j] == 2){
                    ans++;
                }
                if(cnt[j] == 0){
                    continue;
                }
                while(head <= tail && dp[q[tail]] > dp[j]){
                    tail--;
                }
                q[++tail] = j;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}