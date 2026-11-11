#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m;
long long a[N], ans = 1, ttt[N], sum1[N], sum2[N];
vector<pair<long long, long long> > v;
long long l = 1, r = 1;
//first是能量，second是个数 

long long update() {
	long long res = sum2[r] - sum2[l - 1];
	if(l > 1) res += (m - (v[r].first * (sum2[r] - sum2[l - 1]) - (sum1[r] - sum1[l - 1]))) / (v[r].first - v[l - 1].first);
	return res;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	long long maxn = 0;
	for(long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	long long cnt = 1;
	v.push_back({0, 0});
	v.push_back({a[1], 1});
	for(long long i = 2; i <= n; i++) {
		if(v[cnt].first == a[i]) v[cnt].second++;
		else {
			cnt++;
			v.push_back({a[i], 1});
		}
	}
	sum1[1] = v[1].first * v[1].second;		//sum1[i]表示从第1列到现在一共多少个方块 
	for(long long i = 2; i <= cnt; i++) sum1[i] = sum1[i - 1] + v[i].first * v[i].second;
	sum2[1] = v[1].second;					//sum2[i]表示从第1  到现在一共有多少列
	for(long long i = 2; i <= cnt; i++) sum2[i] = sum2[i - 1] + v[i].second;
	while(r <= cnt) {
//		cout << l << ' ' << r << ' ' << ans << endl;
		if(v[r].first * (sum2[r] - sum2[l - 1]) - (sum1[r] - sum1[l - 1]) > m) {
			l++;
			if(l > r) r = l;
			if(v[r].first * (sum2[r] - sum2[l - 1]) - (sum1[r] - sum1[l - 1]) <= m) {
				ans = max(ans, update());
			}
		} 
		else {
			r++;
			if(v[r].first * (sum2[r] - sum2[l - 1]) - (sum1[r] - sum1[l - 1]) <= m) ans = max(ans, sum2[r] - sum2[l - 1]);
		}
		
//		cout  << l << ' ' << r << ' ' << ans << endl;
	}
	cout << ans << endl;
//	for(long long i = 1; i <= n; i ++) cout << sum1[i] << ' ';
//	for(int i = 1; i <= cnt; i++) cout << v[i].first << ' ' << v[i].second << endl;
//	cout << cnt;
	return 0;
}

