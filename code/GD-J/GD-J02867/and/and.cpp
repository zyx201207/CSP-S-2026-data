#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a[200010], n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = a[n];
	int cnt = n;
	while (cnt > n-m){
		if ((a[cnt]&(a[cnt]-1))==0){
			cnt--;
			n++;
			continue;
		}
		else ans = ans & a[cnt];
		cnt--;
	}
//	for (int i = n; i > n-m; i--){
//		maxn = (maxn & a[i]);
//	}
	cout << ans;
	return 0;
} 
