#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],p,l=1,ans,pans;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		p+=pans*(a[i]-a[i-1]);
		while (p>m) p-=(a[i]-a[l++]);
		pans=i-l+1;
		ans=max(ans,pans);
	}
	cout<<ans;
	return 0;
}

