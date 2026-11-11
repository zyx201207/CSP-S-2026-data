#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005],d[500005],ans = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    bool f = 1;
    for(int i = 1;i <= n;i++){
        d[i] = a[i] - a[i-1];
        if(i > 1 && d[i] != d[i-1]) f = 0;
    }
    if(f){
        ll di = m / (a[2] - a[1]);
        for(int i = 1;i < n;i++){
            di -= i;
            if(di < 0) break;
            ans++;
        }
        if(ans > n) ans = n;
        printf("%lld",ans);
        return 0;
    }
    for(int i = n;i >= 2;i--){
        ll sum = 0,cnt = 1;
        for(int j = i-1;j >= 1;j--){
            sum += a[i] - a[j];
            if(sum > m) break;
            cnt++;
        }
        ans = max(ans,cnt);
        if(ans == i) break;
    }
    if(ans > n) ans = n;
    printf("%lld",ans);
    return 0;
}
