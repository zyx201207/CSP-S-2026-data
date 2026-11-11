#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,l;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=l=1;
	for(int i=2;i<=n;i++) {
		while(m<(i-l)*(a[i]-a[i-1])) {
			m+=a[i-1]-a[l];
			l++;
		}
		m-=(i-l)*(a[i]-a[i-1]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
