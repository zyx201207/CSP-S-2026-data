#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long flag=-0x3f3f3f3f;//has same nember
long long tong[1000006];
long long a[200005];
string ta[200005];
bool cmp(long long x,long long y)
{
	return x>y;
}
string ten_to_two(long long x)
{
	long long i=0;
    string s;
	while(((x+1)/2)!=0)
	{
		long long t=x%2;
		char tt=t+'0';
		s+=tt;
		x/=2;
		i++;
	}
	string ts;
	for(long long j=0;j<i;j++)
	{
		ts+=s[i-j-1];
	}
	return ts;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		tong[a[i]]++;
		if(tong[a[i]]>=2)
		{
			flag=max(flag,a[i]);
		}
		string t=ten_to_two(a[i]);
		ta[i]=t;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
	}
	else if(m==2)
	{
		long long maxx=-0x3f3f3f3f;
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n)
	{
		long long t=a[1];
		for(long long i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		cout<<t;
	}
	else if(m==n-1)
	{
		for(long long q=1;q<=n;q++)
		{
			long long t=a[1];
			for(long long i=2;i<=n;i++)
			{
				if(i!=q) t=t&a[i];	
			}
			cout<<t;
		}
	}
	else if(flag!=-0x3f3f3f3f) 
	{
		cout<<flag;
	}
	else
	{
		long long ans=a[1];
		for(long long i=2;i<=m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
