#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],maxn,ans,f=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]+1!=i) f=0;
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++) cnt&=a[i];
		cout<<cnt;
		return 0;
	}
	if(f==1)
	{
		cout<<n-m;
		return 0;
	}
	if(m==2) 
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	ans=0;
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=2;j<=n;j++)
			{
				if(i!=1) sum=a[1];
				else sum=a[2];
				if(i==j) continue;
				if(i==1) j++;
				sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	int o=maxn+1,flag;
	for(int i=1;i<32;i++)
	{
		if(pow(2,i)==o)
		{
			flag=1;
			break;
		}
		if(pow(2,i)>o)
		{
			break;
		}
	}
	if(flag==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	cout<<0;
}
