#include <bits/stdc++.h>
using namespace std;


long long n,m,sum = 1,ma = 0,k;
long long a[5000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a + n + 1);
    for(int i = n;i >= 1;i--){
        k = m;
        sum = 1;
        for(int j = i - 1;j >= 1;j--){
            long long ans = a[i] - a[j];
            if(k >= ans){
                k -= ans;
                sum++;
            }else{
                break;
            }
        }
        if(sum > ma){
            ma = sum;
        }
     }
    printf("%lld",ma);
    return 0;
}
