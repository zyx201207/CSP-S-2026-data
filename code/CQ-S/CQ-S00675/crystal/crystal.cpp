#include<bits/stdc++.h>
#define ll long long
//#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pii pair<int, int>
#define lowq(type) priority_queue<type, vector<type>, greater<type>>
using namespace std;
const int N = 5e5 + 5;
int n;
ll a[N], xx[N];
unordered_map<ll, ll> mp;
ll m, ans;
ll pre[N];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fastio;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		xx[i] = a[i];
		mp[a[i]]++;
	}
	sort(xx + 1, xx + 1 + n);
	int cnt = unique(xx + 1, xx + 1 + n) - xx - 1;
	int r = cnt - 1;
	ll tmp = m, tmpp = 0;
	ll last = 0, las = 0;
	for(int i = 1; i <= cnt; i++) {
		pre[i] = pre[i - 1] + mp[xx[i]];
	}
	//cout << pre[cnt] <<endl;
	for(int i = cnt; i >= 1; i--) {
	//	cout << last << endl;
		tmp += last;
		last = 0;
		las = 0;
	//	cout << "i: "<< i << " tmp1: " << tmp << endl;
		while(r >= 1) {
			if(i == r) r--;
			ll c = tmp / (xx[i] - xx[r]);
			//cout << tmp << endl;
		//	cout << "R: " << r << " C: " << c << endl;
			if(mp[xx[r]] <= c) {
				tmp -= (xx[i] - xx[r]) * mp[xx[r]];
				r--;
			} else {
				las += c;
				break;
			}
		}
		last = (pre[i - 1] - pre[r]) * (xx[i] - xx[i - 1]);
		//cout << i << " " << r << endl;
	//	cout << pre[i] - pre[r] + las << endl;
		ans = max(ans, pre[i] - pre[r] + las);
		//cout << "i: "<< i << " tmp2: " << tmp << endl;
	}
	cout << ans << endl;
	return 0;
}

