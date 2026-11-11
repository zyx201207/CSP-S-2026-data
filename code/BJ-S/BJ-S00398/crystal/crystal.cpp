#include <bits/stdc++.h>
using namespace std;
long long a[500001],sum[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0,i = 1,j = 1;
    while(j <= n){
        long long mid = a[j] * (j - i + 1);
        if(mid - (sum[j] - sum[i - 1]) <= m){
            ans = max(ans,j - i + 1);
            j++;
        }
        else{
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}
