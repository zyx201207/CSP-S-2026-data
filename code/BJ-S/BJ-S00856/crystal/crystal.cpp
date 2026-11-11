#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, l, r, mid, ans;
ll m, a[maxn], pre[maxn];
bool check(int x){
    for(int i = x; i <= n; ++i)
        if(a[i] * x - (pre[i] - pre[i - x]) <= m) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    l = 1, r = n;
    while(l <= r){
        mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}