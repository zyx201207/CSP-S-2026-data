#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int cs[1000000];
int sums[1000000];

int calc(int l, int r){
	return (r - l) * cs[r] - (sums[r - 1] - sums[l - 1]);
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> cs[i];
	}
	sort(cs + 1, cs + 1 + n);
	for (int i = 1;i <= n;i++){
		sums[i] = sums[i - 1] + cs[i];
	}
	int l = 1,r = 1;
	int ans = 1;
	while (r <= n){
		while (r <= n && calc(l, r) <= m) r++;
		ans = max(ans, r - l);
		while (l <= r && calc(l, r) > m) l++;
//		cout << l <<< " " << r << endl;
	}
	cout << ans;
}
