#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr static const int maxn = 2e5 + 5, BIT = 31;

int n, m, a[maxn], ans, tar = -1;
vector<int> v[BIT];
bool dead[1 << 30];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    if (m == n) {
        for (int i = 1, t; i <= n; i++) {
            cin >> t;
            if (i == 1) ans = t;
            else ans &= t;
        }
        cout << ans;
        return 0;
    }
    if (m == 1) {
        for (int i = 1, t; i <= n; i++) {
            cin >> t;
            ans = max(ans, t);
        }
        cout << ans;
        return 0;
    }
    if (m == 2) {
    	for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 30; j >= 0; j--) if ((a[i] >> j) & 1) {
            v[j].push_back(a[i]);
        }
    }
    for (int j = 30; j >= 0; j--) if (v[j].size() >= m) {
        tar = j;
        break;
    }
    if (tar == -1) {
        cout << 0;
        return 0;
    }
    for (int j = 30; j >= 0; j--) {
        int cnt = 0;
        for (int i : v[tar]) if (!dead[i]) {
            if ((i >> j) & 1) cnt++;
            else dead[i] = 1;
        }
        if (cnt >= m) ans |= 1 << j;
        else {
            memset(dead, 0, sizeof dead);
        }
    }
    cout << ans;
    return 0;
}
