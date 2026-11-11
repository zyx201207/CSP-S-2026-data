//ok
#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500001],p[500001];

int check (int l,int r,int n){
	int mid;
	int ll = l,rr = r;
	while (l <= r){
		mid = l + (r - l) / 2;
		int cnt = a[mid] * (mid - ll + 1) - (p[mid] - p[ll - 1]);
		if (cnt <= n) l = mid + 1;
		else r = mid - 1;
	}
	return r - ll + 1;
}

signed main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	
	sort (a + 1,a + n + 1);
	
	for (int i = 1;i <= n;i ++){
		p[i] = p[i - 1] + a[i];
	}
	
	int ans = -1;
	for (int i = 1;i <= n;i ++){
		ans = max (ans,check (i,n,m));
	}
	
	cout << ans;
	return 0;
}
