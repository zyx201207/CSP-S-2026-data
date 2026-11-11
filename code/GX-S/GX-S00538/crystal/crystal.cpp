#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
inline bool clec(long long mid){
    for (long long i = mid;i <= n;i++){
        if (m >= a[i] * mid - b[i] + b[i - mid]) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++){
        b[i] = b[i - 1] + a[i];
    }
    long long l = 0,r = n + 1;
    while (l + 1 < r){
        long long mid = (l + r) / 2LL;
        if (clec(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}
