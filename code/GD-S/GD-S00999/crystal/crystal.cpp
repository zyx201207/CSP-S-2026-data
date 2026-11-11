#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],c[500005],ans;


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
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r) /2;
		for(int i=1;i<=mid;i++)c[i]=a[mid]-a[i];
		long long m1=mid-1,k=1,m2=m;
		while(m2>0)
		{
			if(m1<1)break;
			m2-=c[m1];
			m1--;
			k++;
		}
		if(m2>=0)
		{
			l=mid+1;
			ans=max(ans,k);
		}
		else r=mid-1;
	}
	l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r) /2;
		for(int i=1;i<=mid;i++)c[i]=a[mid]-a[i];
		long long m1=mid-1,k=1,m2=m;
		while(m2>0)
		{
			if(m1<1)break;
			m2-=c[m1];
			m1--;
			k++;
		}
		l=mid+1;
		ans=max(ans,k);
		
	}
	l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r) /2;
		for(int i=1;i<=mid;i++)c[i]=a[mid]-a[i];
		long long m1=mid-1,k=1,m2=m;
		while(m2>0)
		{
			if(m1<1)break;
			m2-=c[m1];
			m1--;
			k++;
		}
		r=mid;
		ans=max(ans,k);
		
	}
	cout<<ans;
} 
