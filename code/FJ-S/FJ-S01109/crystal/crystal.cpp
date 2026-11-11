#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,now;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int j=n-1;ans=1;
	for(int i=n;i>=1;i--)
	{
		while(j>0&&now+a[i]-a[j]<=m)
		{now+=a[i]-a[j];j--;}
		ans=max(ans,i-j);
		now-=(i-j-1)*(a[i]-a[i-1]);
	}
	cout<<ans;
	return 0;
}

