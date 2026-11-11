#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e5 + 10;

ll a[N];
ll sum[N];
priority_queue<ll> pq;

ll evalr(ll l, ll r) {
  ll rsum = sum[r - 1] - sum[l - 1];
  ll rmax = a[r];
  // cerr << "eval  " << rsum << ' ' << rmax << endl;
  ll score = (ll)1 * rmax * (r - l) - rsum;

  return score;
}

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);
  for (ll i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  ll l = 1, r = 2;
  pq.push(a[1]);
  ll maxn = 1;
  while (r <= n + 1) {
    ll score = evalr(l, r);
    // cerr << "l: " << l << ' ' << "r: " << r << ' ' << "score: " << score << endl;
    if (score > m) {
      l++;
    } else {
      maxn = max(maxn, r - l);
      r++;
      // cerr << "maxn: " << r - l << endl;
    }
  }

  cout << maxn + 1 << endl;
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
