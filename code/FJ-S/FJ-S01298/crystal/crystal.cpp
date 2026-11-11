#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],s[N],ans;
bool check(int l,int r) {
//	return c[r]-c[l-1]<=m;
	int res=(r-l)*a[r]-(s[r-1]-s[l-1]);
	return res<=m;
}
int solve(int l) {
	int r=n,p=l;
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(check(p,mid)) l=mid;
		else r=mid-1;
	}
	return l-p+1;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];         //0 1 2 4 8 9
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		ans=max(solve(i),ans);
	}
	cout<<ans;
	return 0;
}
