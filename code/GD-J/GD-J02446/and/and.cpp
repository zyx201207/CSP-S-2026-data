#include <bits/stdc++.h>
using namespace std;
int n,m,b,maxx=0,maxxx=0,maxxxx=0;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			b=b&a[i];
		}
		cout<<b;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i>1&&maxx!=maxxx)
				maxxx=maxx;
			maxx=max(b,a[i]);
		}
		maxxxx=maxx&maxxx;
		cout<<maxxxx;
	}
	return 0;
}
