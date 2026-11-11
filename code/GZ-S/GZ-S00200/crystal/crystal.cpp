//陈超 GZ-S00200 盘州市第二中学
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 500010, INF = 0x3f3f3f3f;
#define int long long
/*
排序 二分
1 2 4 8 9
0 1 5 17 21
*/

int n, m;
int a[N], b[N], c[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        b[i] = a[i] - a[i-1];
        c[i] = b[i] * (i - 1) + c[i-1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        int mid;
        while(l < r){
            mid = l + r >> 1;
            if(c[i] - c[mid] - (mid - 1) * (a[i] - a[mid]) <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - r + 1);
        //cout << i << ' ' << mid << ' ' << c[i] - c[mid] << endl;
    }
    cout << ans <<endl;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T = 1;
    while(T--) solve();
    return 0;
}
