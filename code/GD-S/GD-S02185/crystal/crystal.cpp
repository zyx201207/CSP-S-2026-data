#include<bits/stdc++.h>
#define fs first
#define sc second
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, k, ans;
int a[N], t[N];
vector<int> v;

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	
	k = v.size();
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		t[a[i]]++;
	}
	
	sort(a + 1, a + n + 1);
	int l = 1, r = t[0], cost = 0;
	ans = r - l + 1;
	for(int i = 1;i < k;i++){
		cost += (r - l + 1) * (v[i] - v[i - 1]);
		while(cost > m) cost -= v[i] - v[a[l++]];
		r += t[i];
		ans = max(ans, r - l + 1);
	}
	
	cout << ans;
	
	return 0;
	
}
