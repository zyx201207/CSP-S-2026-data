#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5 * 1e5 + 1;
vector<ll> vec;
ll n, m, a;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	ll sum = 0, cnt = 0, maxn = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		sum = 0, cnt = 0, flag = false;
		for (int j = i; j >= 0; j--) {
			int s = (vec[i] - vec[j]);
			sum += s;
			cnt += 1;
			if (sum > m) break;
			if (maxn < cnt) maxn = cnt;
		}
	}
	cout << maxn;
	return 0;
 } 
