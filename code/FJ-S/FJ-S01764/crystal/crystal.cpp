#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
bool check(int x)
{
	for(int i=x;i<=n;i++)
		if(s[i]-s[i-x]+m>=x*a[i])
			return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}