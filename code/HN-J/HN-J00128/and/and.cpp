#include <bits/stdc++.h>
using namespace std;
int n,m;
long long s=0;
long long a[200010],b[10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ma=0,mi=(1<<21);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(n==m)
	{
		s=a[1];
		for(int i=2;i<=n;i++)
		{
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
		return 0;
	}
	if(ma<=4)
	{
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
		}
		if(b[4]>=m)
		{
			cout<<4;
		}
		else if(b[3]>=m)
		{
			cout<<3;
		}
		else if(b[2]+b[4]>=m)
		{
			cout<<2;
		}
		else if(b[1]+b[3]>=m)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0; 
	}
	cout<<mi;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
