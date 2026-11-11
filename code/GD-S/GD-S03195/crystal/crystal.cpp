#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=1;
	if(n>=5000)
	{
		long long k=a[1]-a[0];
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=i;
			if(m>=sum*k)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	long long ans1=0;
	long long t=m;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[n-1]-a[i];
	}
	if(sum<t)
	{
		cout<<n-1;
		return 0;
	}
	if(sum==t)
	{
		cout<<n;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(t>=a[i]-a[j])
			{
				t-=a[i]-a[j];
				ans1++;
			}
			else
			{
				t=0;
			}
		}
		int x=i;
		for(int j=i;j<n;j++)
		{
			if(a[j]==a[i])
			{
				ans1++;
				x++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans1,ans);
		t=m;
		ans1=0;
	}
	cout<<ans;
}
