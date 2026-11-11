#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
signed main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		b[i] = b[i-1]+a[i];
	}
	int ans = 0;
	for (int i = 1;i <= n;i++){
		int sum = i*a[i];
		if (sum-b[i] <= m) ans = i;
	}
	cout << ans;
	return 0;
}
