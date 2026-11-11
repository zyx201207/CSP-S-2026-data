#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500010],t;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		a[0]=0;
		for(int i=n,j;i>ans;i--)
		{
			t=m,j=i;
			while(t>=a[i]-a[j-1]&&j>1)t-=a[i]-a[j-1],--j;
			ans=max(ans,i-j+1);
		}
		cout<<ans;
		return 0;
	}
	long long s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=0;
	for(int i=n,j,d;i>ans;i--)
	{
		t=m,j=i-1,d=a[i]-a[i-1];
		while(t>0&&j>1)
		{
			while(a[j]-a[j-1]==d)--j;
			s=(a[i]-a[i-1]+a[i]-a[j])*(i-j)/2;
			if(s>t)
			{
				j=i;
				while(t>=a[i]-a[j-1]&&j>1)t-=a[i]-a[j-1],--j;
				ans=max(ans,i-j+1);
				cout<<ans;
				return 0;
			}
			t-=s;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
