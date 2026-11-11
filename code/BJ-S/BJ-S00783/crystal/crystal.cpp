#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (b); i >= (a); i--)
#define rp(i, a) for(int i = 1; i <= (a); i++)
#define pr(i, a) for(int i = (a); i >= 1; i--)
#define ll long long
#define db double
#define pb push_back
#define si(x) (int)(x).size()
#define ft first
#define sd second
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define endl '\n'
const ll Mod = 1000000007ll;
//const ll Mod = 998244353ll;
const ll B = 13131ll;

int n;
ll m;
ll a[500005], b[500005];
int ans;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
//    cout << "n = " << n << endl;
    rp(i, n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    rp(i, n) {
        b[i] = b[i - 1] + a[i];
    }
    rp(i, n) {
//        cout << "i = " << i << endl;
        int l = 1, r = i, res = i;
        while(l <= r) {
            int mid = (l + r) / 2;
            if((i - mid + 1ll) * a[i] - (b[i] - b[mid - 1]) <= m) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans << endl;
    return 0;
}
