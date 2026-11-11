#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 500005;
int n, m, a[N], s[N], ans;

int qry(const int &l, const int &r){
    return a[r] * (r - l + 1) - (s[r] - s[l-1]);
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i ++)
        s[i] = s[i-1] + a[i];
    int r = 1;
    for(int l = 1; l <= n; l ++){
        while(r < n && qry(l, r+1) <= m)
            ++ r;
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
