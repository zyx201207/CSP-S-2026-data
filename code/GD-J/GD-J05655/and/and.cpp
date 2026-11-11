#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==2)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					cnt=max(cnt,a[i]&a[j]);
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<0;
}
