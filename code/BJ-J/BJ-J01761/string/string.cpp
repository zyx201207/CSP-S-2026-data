#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef __int128 LL;
typedef unsigned long long ull;

ll cnt[200200];
char type[200200];

int main() {
    #ifndef LOCAL
        freopen("string.in", "r", stdin);
        freopen("string.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    ll n;
    std::cin >> n;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> cnt[i] >> type[i];
        tot += cnt[i];
    }
    std::vector<ll> p;
    ll sum = cnt[1];
    for (int i = 1; sum <= tot / 2; i++, sum += cnt[i]) {
        p.push_back(sum);
    }
    sum = cnt[n];
    for (int i = n; sum <= tot / 2; i--, sum += cnt[i]) {
        p.push_back(sum);
    }
    p.push_back(0), p.push_back(tot / 2);
    std::sort(p.begin(), p.end());
    sum = 0;
    ll h = 1, t = n;
    ll sh = cnt[1], sl = cnt[n];
    for (int i = 1; i < p.size(); i++) {
        if (sh < p[i]) {
            sh += cnt[++h];
        }
        if (sl < p[i]) {
            sl += cnt[--t];
        }
        if (type[h] != type[t]) {
            sum += p[i] - p[i - 1];
        }
    }
    std::cout << sum;
    return 0;
}