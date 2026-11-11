#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
long long f(long long x){
    long long l = 1,r = x - 1;
    long long res = -1;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(sum[x - 1] - sum[mid - 1] + m >= (x - 1 - mid + 1) * a[x]){
            res = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return res;
}
long long ans = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i ++){
        long long p = f(i);
        if(p == -1){
            continue;
        }
        else{
            ans = max(ans,i - p + 1);
        }
    }
    cout << ans << endl;
    return 0;
}