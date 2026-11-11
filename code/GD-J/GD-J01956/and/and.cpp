#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005],maxn;
int main()
{
	freopen('and.in','r',stdin);
	freopen('and.out','w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int s=a[1];
		for(int i=2;i<=n;i++)
		{
			s=s&a[i];
		}
		cout<<s;
	}
}
