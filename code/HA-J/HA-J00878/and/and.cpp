#include<bits/stdc++.h>
using namespace std;
int a[200005];
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
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
	}
	else if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else if(m==2)
	{
		int cnt,maxx=0;
		for(int i=1;i<=n;i++)
		{
			cnt=a[i];
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(cnt&a[j],maxx);
			}
		}
		cout<<maxx;
	}
	return 0;
}
