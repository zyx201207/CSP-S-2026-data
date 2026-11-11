/*
  Author: acmpGu
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)

const ll mod = 998244353;
// const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

/* --- Template End Here --- */

const int MAXN = 5e5 + 9;

int n;
ll m;
ll a[MAXN];
ll s[MAXN];
int res = 0;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ifstream cin("crystal.in");
    ofstream cout("crystal.out");

    cin >> n >> m;

    rep (i, 1, n) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    rep (i, 1, n) {
        s[i] = s[i - 1] + a[i];
    }

    rep (i, 1, n) {
        int l = 0, r = n - i + 1;
        int ans = 0;

        if (r <= res) {
            break;
        }
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            int j = i + mid - 1;

            if (a[j] * (j - i + 1) - (s[j] - s[i - 1]) <= m) {
                ans = mid;
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        res = max(res, ans);
    }

    cout << res << '\n';

    return 0;

}