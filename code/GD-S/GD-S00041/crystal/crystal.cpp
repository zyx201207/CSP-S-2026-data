#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
ll n, m;
ll arr[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) cin >> arr[i];
	int jc = arr[2] - arr[1];
	if(n % 2 == 1) {
		ll cnt = 0;
		ll mid = n / 2 + 1;
		ll sum = 0, ty = 1, jian = jc;
		while(sum <= m) {
			if(ty == 1) {
				if(sum + jian > m) break;
				sum += jian;
				ty++;
				cnt++;
			}
			else if(ty == 2) {
				if(sum + jian > m) break;
				sum += jian;
				ty = 1, jian += jc;
				cnt++;
			}
		}
		cout << min(cnt, n);
	}
	else {
		ll cnt = 0;
		cnt++;
		ll mid = n / 2 + 1;
		ll sum = 0, ty = 1, jian = jc;
		while(sum <= m) {
			if(ty == 1) {
				if(sum + jian > m) break;
				sum += jian;
				ty++;
				cnt++;
			}
			else if(ty == 2) {
				if(sum + jian > m) break;
				sum += jian;
				ty = 1, jian += jc;
				cnt++;
			}
		}
		cout << min(cnt, n);
	}
	return 0;
}

