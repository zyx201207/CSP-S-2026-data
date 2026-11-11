#include <bits/stdc++.h>
using namespace std;
#define deb(n) cout << #n << " = " << n << '\n';
#define int long long
const int N = 2e5 + 10;
struct Node {
	int cnt;
	char c;
}a[N];
int n;
int idx = 0;
int now = 0; 
int mid = 1;
int sum = 0;
bool check() {
	if (sum & 1 && a[mid].cnt & 1 && now + (a[mid].cnt + 1 >> 1) == (sum + 1 >> 1)) return true;
	else if (!(sum & 1) && !(a[mid].cnt & 1) && now + (a[mid].cnt >> 1) == sum >> 1) return true;
	return false;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cnt;
		char c;
		cin >> cnt >> c;
		if (idx > 0 && c == a[idx].c) {
			a[idx].cnt += cnt;
		}
		else a[++idx] = {cnt, c};
	}
	if (idx == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= idx; i++) sum += a[i].cnt;
//	deb(sum);	
	
	for (int i = 1; i <= idx; i++) {
		if (now + a[i].cnt > (sum >> 1)) {
			mid = i;
			break;	
		}
		now += a[i].cnt;
	}
//	deb(mid);
	int i = a[1].cnt;
	int ii = 1, ij = idx; // об╠Й 
	int ans1 = 0;
	bool f = false;
	while (i <= mid) {
		int t = a[ii].cnt;
//		deb(t);
		while (t > 0) {
//			deb(t);
//			deb(ii);
//			deb(ij); 
//			deb(a[ii].cnt);
//			deb(a[ij].cnt);
//			deb(a[ii].c);
//			deb(a[ij].c);
			if (a[ij].cnt <= t) {
				if (a[ij].c != a[ii].c) ans1 += a[ij].cnt;
				t -= a[ij].cnt;
			} else {
				if (a[ij].c != a[ii].c) {
					ans1 += a[ij].cnt - t;
				}
//				a[ij].c = a[ii].c;
				a[ij].cnt -= t;
				break;
			}
			ij--;
			if (ij <= mid) {
				f = true;
				break;
			}
		}
		if (f) break;
//		deb(ans1);
		i += a[ii].cnt;
		ii++;
	}
//	deb(now);
//	deb(ans1);
//	deb(now + a[mid].cnt);
//	deb((sum + 1 >> 1) - now);
//	deb(now + a[mid].cnt - (sum + 1 >> 1));
//	
//	deb(ii); 
	if (!check()) ans1 += abs((sum + 1 >> 1) - now - (now + a[mid].cnt - (sum + 1 >> 1)));
	cout << ans1;
	return 0;
} 
