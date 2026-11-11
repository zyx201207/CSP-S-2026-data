#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int a[N], s[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for(int l = 1, r = 1; r <= n; r++){
		int len = r - l + 1;
		int sum = s[r] - s[l - 1];
		int mr = a[r];
		int sm = 0;
		int pos = lower_bound(a + l, a + r + 1, mr) - a;
		sm += abs(mr * (pos - l) - (s[pos - 1] - s[l - 1]));
		sm += abs((s[r] - s[pos - 1]) - mr * (r - pos + 1));
		while(sm > m){
			l++;
			len = r - l + 1;
			mr = a[r];
			sm = 0;
			pos = lower_bound(a + l, a + r + 1, mr) - a;
			sm += abs(mr * (pos - l) - (s[pos - 1] - s[l - 1]));
			sm += abs((s[r] - s[pos - 1]) - mr * (r - pos + 1));
		}
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
} 
