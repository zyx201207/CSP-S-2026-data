#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],s[500010],n,m;
bool check(int mid)
{
	for(int i=1;i+mid-1<=n;i++)
	{
		if(a[i+mid-1]*(mid-1)-(s[i+mid-2]-s[i-1])<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid)) l=mid+1,res=mid;
		else r=mid-1;
	}
	cout<<res;
	return 0;
}
