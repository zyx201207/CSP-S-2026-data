#include <bits/stdc++.h>
using namespace std;
int n; 
long long m,a[500005];
bool check(int x) {
	long long ans = 0;
	for(int i = 1;i<=x;i++) {
		ans+=(a[x]-a[i]);
	}
	return (ans<=m);
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1;
	int l = 1,r = n;
	while(l<=r) {
		int mid = (l+r)/2;
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		}else {
			r = mid-1;
		}
	}
	long long x = a[ans];
	cout<<ans;
	return 0;
}
