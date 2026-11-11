#include<bits/stdc++.h>
using namespace std;
int a[2005],s[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		long long max=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long tmp=a[i]&a[j];
				if(tmp>=max) max=tmp;
			}
		}
		cout<<max;
		return 0;
	}
	if(m==1)
	{
		int max=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=max) max=a[i];
		}
		cout<<max;
		return 0;
	}
	if(m==n)
	{
		s[1]=a[1];
		for(int i=2;i<=n;i++) s[i]=s[i-1]&a[i];
		cout<<s[n];
	}
	return 0;
}