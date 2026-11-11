#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans[500010],a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		cout<<n;
		return 0;
	}
	if((n-1)*(a[2]-a[1])==a[n]-a[1])
	{
		s=a[2]-a[1];
		x=0;
		for(int i=1;i<=n;i++)
		{
			x+=i*s;
			if(x<=m) ans[1]++;
			else break;
		}
		cout<<ans[1]+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s=0;
		for(int j=i-1;j>=1;j--)
		{
			s+=a[i]-a[j];
			if(s<=m) ans[i]++;
			else break;
		}
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n]+1;
	return 0;
}
