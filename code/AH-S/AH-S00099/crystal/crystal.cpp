//100 pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int ans = 0;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt = 0;
	int l = 1;
	for (int r = 2;r<=n;r++) {
		cnt+=(a[r]-a[r-1])*(r-l);
		if (cnt>m) {
			ans = max(r-l,ans);
			while (r>=l&&cnt>m) cnt-=(a[r+1]-a[l]),l++;
		} 
	}
	cout<<ans<<endl;
	return 0;
}
