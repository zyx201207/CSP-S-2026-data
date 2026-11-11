#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[500010], b[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll yve = m, cnt = 1, ans = 0;
	for(ll i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(ll i=1; i<=n; i++) {
		b[i] = a[i];
	}
	a[n+1] = a[n];
	for(ll i=1; i<n; i++) {
		if(a[i+1] - b[i] > m) {
			yve = m;
			cnt = 1;
			continue;
		}
		if((a[i+1]-b[i]) * cnt <= yve) {
			yve -= (a[i+1]-b[i]) * cnt;
			cnt++;
			b[i] = a[i+1];
		} else {
			while((a[i+1]-b[i]) * cnt > yve) {
				yve += b[i] - a[i-cnt+1];
				cnt--;
//				cout << "in:" << cnt  << ' ' << yve << endl;
			}
			yve -= (a[i+1]-b[i]) * cnt;
			cnt++;
		}
		ans = max(ans, cnt);
//		cout << cnt  << ' ' << yve << endl;
	}
	cout << ans;
	return 0;
}

//10 10
//1 3 5 6 10 10 10 10 12 12 12
