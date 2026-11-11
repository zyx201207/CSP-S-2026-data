//GZ-J00003 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long e[30];
long long n,m;
bool cmp(long long a,long long b)
{
	return a>b;
}
bool cheak(int n)
{
	int cnt=0;
	for(int i=1;i<=20;i++)
	{
		e[i]=0;
	}
	while(n>0)
	{
		e[++cnt]=n%2;
		n/=2;
	}
	int res=0;
	for(int i=1;i<30;i++)
	{
		if(e[i]==1) res++;
	}
	if(res!=m) return 0;
	else
	{
	 	return 1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<=pow(2,n);i++)
		{
			bool o=0;
			long long k=0;
			if(cheak(i)==1)
			{
				for(int i=1;i<=n;i++)
				{
					if(e[i]==1&&o==0)
					{
						k=a[i];
						o=1;
					}
					else if(e[i]==1&&o==1)
					{
						k&=a[i];
					}
				}
				ans=max(ans,k);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
