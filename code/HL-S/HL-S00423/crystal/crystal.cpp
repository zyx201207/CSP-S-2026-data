#include<bits/stdc++.h>
#define re register
using namespace std;
const long long  N = 5 * 1e5 + 10;
int n;
long long m,dp[N],a[N],d[N];
bool cmp(long long x,long long y){
    return x < y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    bool flag = 0;
    bool f = 0;
    for(re int i = 1;i <= n;i ++){
        scanf("%lld",&a[i]);
        d[i] = d[i - 1] + a[i];
        dp[i] = 1;
        if(a[i] != i)flag  = 1;
        else if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])f = 1;
    }
    sort(a+1,a+n+1,cmp);
    if(flag == 0 && f == 0){
        int ans = 0;
        long long sum = 0;
        for(re int i = n;i >= 1;i --){
            if(sum + a[n] - a[i] <= m){
                ans ++;
                sum += a[n] - a[i];
            }
        }
        cout << ans;
    }
    else {
        d[1] = 0;
        dp[1]= 1;
        for(re int i = 2;i <= n;i ++){
           long long ans = 0;
            int sum = 0;
            for(re int j = i;j >= 1;j --){
                if(ans + (a[i] - a[j]) <= m){
                    ans += a[i] - a[j];
                    sum ++;
                }
            }
            dp[i] = sum;
        }
            /*int l = 1,r = i;
            while(l <= r){
                int mid = (l + r) >> 1;
                if((mid * a[i]) - (d[i] - d[mid ]) <= m){
                    l = mid + 1;

                }
                else r = mid - 1;
            }
            dp[i] = l;*/
    /*    if(d[i - 1] + (a[i] - a[i - 1]) * dp[i - 1] <= m){
            dp[i] = dp[i - 1] + 1;
            d[i] = d[i - 1] + (a[i] - a[i - 1]) * dp[i - 1];
        }*/

    }
    long long mx = -0x7f7f7f7f;
    for(re int i = 1;i <= n;i ++){
        mx= max(dp[i],mx);

    }
    cout << mx;
	return 0;
}
