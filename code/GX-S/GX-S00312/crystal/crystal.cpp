#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using LL = long long;

constexpr int MAX_N = 5e5+7;

int n;
LL m, a[MAX_N], sum[MAX_N];

bool cmp(LL x, LL y) {
    return x > y;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    LL s = 0;
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i-1] + a[i];
        s += a[i];
    }
    //cout << sum[n] << " " << m << " " << a[1] << endl;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int l = i, r = n, mid = 0;
        while(l < r) {
            mid = (l + r + 1) >> 1;
            if(sum[mid] - sum[i-1] + m >= a[i] * LL(mid - i + 1)) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l - i + 1);
    }
    cout << ans << endl;
    return 0;
}
