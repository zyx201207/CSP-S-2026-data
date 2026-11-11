//GZ-S00333,lijunshen
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
bool check(int x){
	int s = 0;
	for (int i = 1;i < x;i++){
		s += a[x]-a[i];
	}
	for (int i = x;i <= n;i++){
		if(s <= m)return true;
		s -= a[i]-a[i-x+1];
		s += (a[i+1]-a[i])*(x-1);
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1, a+n+1);
	int l = 1, r = n, mid;
	while (l <= r){
		mid = (l+r)/2;
		if (check(mid))l = mid+1;
		else r = mid-1;
	}
	cout << r;
	return 0;
}
