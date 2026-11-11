#include <cstdio>
#include <stack>

using namespace std;

typedef long long ll;

const ll MAXN = 500005;
const ll MAXM = 300005;

ll a[MAXN];
stack<ll> st;
ll cnt[MAXM];
ll ans[MAXM];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ll n, m;
    scanf("%lld %lld", &n, &m);

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (ll i = 1; i <= n; ++i) {
        for (ll j = i; j <= n; ++j) {
            while (cnt[a[j]] > 0 && st.empty() == false) {
                --cnt[st.top()];
                st.pop();
            }
            st.push(a[j]);
            ++cnt[a[j]];
        }

        while (st.empty() == false) {
            ++ans[st.top()];
            st.pop();
        }

        for (ll j = 1; j <= m; ++j) {
            cnt[j] = 0;
        }
    }

    for (ll i = 1; i <= m; ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}