#include  <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;

const int maxn = 2e5 + 10;
const int inf = INT_MAX / 2;

ll n, len, ans;//n-->gunmu len-->s长度
vector <pair <ll, ll>> a = {{0, 0}};
vector <int> c = {0};

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);

    cin >> n;
    int idx = 0;//a中个数
    for (int i = 1; i <= n ;i++) {
        ll a_1, c_1;
        char ch;
        cin >> a_1 >> ch;
        c_1 = ch - 'a' + 1;
        len += a_1;
        if (c[idx] != c_1) idx++, a.push_back({a[idx - 1].second + 1, len}), c.push_back(c_1);
        else a[idx].second = len;
      
    }
	
	
	ll mid = 0, m_id = 0, l = 0, r = 0, l_id = 0, r_id = 0;
	if (len % 2 == 0) {
		mid = len >> 1, l = mid, r = mid + 1;
        for (int i = 1; i <= idx; i++) {
            if (a[i].first <= l && a[i].second >= l) {
				l_id = i;
			}
            if (a[i].first <= mid && a[i].second >= mid) {
				m_id = i;
			}
            if (a[i].first <= r && a[i].second >= r) {
				r_id = i;
			}
        }
        
        
        
        for (l = mid, r = mid + 1; l >= 1 && r <= len; l--, r++) {
			if (l < a[l_id].first) l_id--;
			if (r > a[r_id].second) r_id++;
			if (c[l_id] != c[r_id]) ans++;
		}
	}
	
	if (len % 2 == 1) {
		mid = (len + 1) >> 1, l = mid - 1, r = mid + 1;
        for (int i = 1; i <= idx; i++) {
            if (a[i].first <= l && a[i].second >= l) {
				l_id = i;
			}
            if (a[i].first <= mid && a[i].second >= mid) {
				m_id = i;
			}
            if (a[i].first <= r && a[i].second >= r) {
				r_id = i;
			}
        }
     
        
        for (l = mid - 1, r = mid + 1; l >= 1 && r <= len; l--, r++) {
			if (l < a[l_id].first) l_id--;
			if (r > a[r_id].second) r_id++;
			if (c[l_id] != c[r_id]) ans++;
		}
	}
	
	cout << ans;

	return 0;
}
