#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long n,m;
long long sum[N];
long long ans = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    sum[0] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    long long r = n;
    for(long long i = n;i >= 2;i--){
        if(r > i){r = i;}
        while(r - 1 >= 1 && sum[i - 1] - sum[r - 2] + m >= 1ll * a[i] * (i - r + 1)){
            r--;
        }
        ans = max(ans,i - r + 1);

        //cout << r << endl;

    }
    cout << ans;
    return 0;
}
//Oct31==Dec25?
