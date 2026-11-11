//GZ-S00004 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000001];
long long cf[1000001];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool o=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) o=1;
	}
	if(o==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			m-=i;
			if(m>=0&&ans<n) ans++;
		}
		cout<<ans;
		return 0;
	}
	bool y=0;
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i]) y=1;
	}
	if(y==0)
	{
		ans=1;
		long long c=a[2]-a[1];
		for(int i=1;i<=n;i++)
		{
			m-=i*c;
			if(m>=0&&ans<n) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		cf[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long mm=m;
		long long q=0;
		long long cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			q+=cf[j];
			mm-=q;
			if(mm>=0) cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
