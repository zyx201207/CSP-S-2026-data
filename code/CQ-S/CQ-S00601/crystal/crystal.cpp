#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sm[N];
int check(int w)
{
	for(int i=w;i<=n;i++) if(a[i]*w-(sm[i]-sm[i-w])<=m) return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
