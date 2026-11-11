#include<bits/stdc++.h>
using namespace std;

int a[500005],b[500005];
long long check1(long long i,long long n)
{
	return (upper_bound(b+0,b+n,i)-b)-(lower_bound(b+0,b+n,i)-b);
}

int main()
{
//	freopen("E:/HN-S00072/crystal/crystal4.in","r",stdin);
//	freopen("E:/HN-S00072/crystal.txt","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans,anw;
	bool flag;
	flag=true;
	cin>>n>>m;
	if(n>2)
	{
		cin>>a[0]>>a[1];
		anw=a[1]-a[0];
		for(int i=2; i<n; i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]!=anw)
			{
				flag=false;
			}
		}
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
	}
	ans=0;
	if(flag)
	{
		for(long long i=1; 1; i++)
		{
			if(m>i*anw)
			{
				m-=i*anw;
				ans++;
			}
			else
			{
				cout<<min(ans,n);
				return 0;
			}
		}
	}
	sort(a+0,a+n);
	for(int i=0; i<1; i++)
	{
		int q,p;
		q=m;
		p=i;
		p--;
		for(int j=0; j<n; j++)
		{
			b[j]=a[j];
		}
		while(q>0&&p>=0)
		{
			q--;
			b[p]++;
			if(b[p]==b[i])
			{
				p--;
			}
		}
		ans=max(ans,check1(b[i],n));
	}
	for(int i=1; i<n; i++)
	{
		int q,p;
		q=m;
		p=i;
		if(a[i]==a[i-1])
		{
			continue;
		}
		p--;
		for(int j=0; j<n; j++)
		{
			b[j]=a[j];
		}
		while(q>0&&p>=0)
		{
			q--;
			b[p]++;
			if(b[p]==b[i])
			{
				p--;
			}
		}
		ans=max(ans,check1(b[i],n));
	}
	cout<<ans;
	return 0;
}
