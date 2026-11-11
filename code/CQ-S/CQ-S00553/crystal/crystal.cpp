#include <bits/stdc++.h>
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 5e5 + 5;
ll a[N], m;
int n;
int main() {
    FILE("crystal");
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll rem = m, cnt = 1, ans = 1;
    multiset<ll> st;
    st.insert(a[1]);
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1])
            cnt++, ans = max(ans, cnt);
        else {
            while (rem < cnt * (a[i] - a[i - 1])) {
                cnt--;
                ll v = *st.begin();
                st.erase(st.begin());
                rem += a[i - 1] - v;
            }
            rem -= cnt * (a[i] - a[i - 1]);
            cnt++;
            ans = max(ans, cnt);
        }
        st.insert(a[i]);
    }
    cout << ans << '\n';
    return 0;
}
// AC on 14:37