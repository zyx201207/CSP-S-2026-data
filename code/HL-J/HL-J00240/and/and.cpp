#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

long long n,m;
long long a[200005];

bool cmp(long long a,long long b)
{
	return a>b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) {
		cout<<a[1];
		return 0;
	}
	if(m==2)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
			    int p=a[i]&a[j];
				ans=max(ans,p);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
}
