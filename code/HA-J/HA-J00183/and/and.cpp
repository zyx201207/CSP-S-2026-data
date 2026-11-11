#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	vector<int> c(n);
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}
	sort(c.begin(),c.end());
	for(int i=n-1; i>n-1-m; i--) {
		ans=c[i];
	}
	cout<<ans;
	return 0;
}
