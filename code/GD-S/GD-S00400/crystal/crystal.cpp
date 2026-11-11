#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];
int pre[500005];
int ans = -1;
bool check(int l){
	for(int i = 1; i+l-1 <= n; ++i){
		int cost = a[i+l-1]*l-(pre[i+l-1]-pre[i-1]);
		//cout << cost << " ";
		if(cost <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1] + a[i];
	}
	int l = 1, r = n;
	while(l+1 < r){
		int mid = (l+r) >> 1;
		//cout << mid << ":  ";
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
		//cout << "\n";
	}
	if(check(r)) cout << r;
	else cout << l;
	return 0;
}
//17 3
//1 2 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4
