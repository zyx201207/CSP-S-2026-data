#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x = 1,s = 0;
    char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') x = -1;
    for (;isdigit(c);c = getchar()) s = s * 10 + c - '0';
    return x * s;
}
const int N = 5e5 + 5;
int n,ans;
ll m,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for (int i = 1;i <= n;++i) a[i] = read();
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
    for (int i = 1;i <= n;++i){
        int l = 1,r = i;
        while (l <= r){
            int mid = (l + r) / 2;
            if (a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans,i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
