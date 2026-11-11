#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+50;
int n, m, a[N], s, sum, res, l = 1;
map<int, int> mp;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i-1] && i > 1) continue;
		sum += s*(a[i]-a[i-1]);
		s += mp[a[i]];
		while(sum > m && l < i){
			sum -= (a[i]-a[l]);
			l++;
			s--;
		}
		res = max(res, s);
	}
	cout << res;
	return 0;
}