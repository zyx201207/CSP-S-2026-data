#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N];
long long s[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }

    sort(a+1,a+n+1,greater<long long>());

    for(int i = 1;i <= n;i ++) {
        s[i] = a[i];
        s[i] += s[i-1];
    }
    long long ans = 0;
    for(int i = 1;i <= n;i ++) {
        int l = i,r = n,mid = 0;
        long long p = a[i];
        while(l <= r) {
            mid = (l+r) / 2;
            if(p * 1ll * (1ll * mid-i+1ll) - 1ll * (s[mid] - s[i-1]) <= m) {
                ans = max(ans,mid - i + 1ll);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

