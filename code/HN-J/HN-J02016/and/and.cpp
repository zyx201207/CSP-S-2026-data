#include<bits/stdc++.h>
using namespace std;
int n,m,anss,anss2,andsum,maxx=-INT_MAX;
int a[20010],andmax[20010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    if(i==1)
	    	andsum=a[i];
		else
		    andsum=andsum&a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==m)
	{
	    cout<<andsum;
	    return 0;
	}
	if(m==1)
	{
	    cout<<maxx;
	    return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			anss=max(anss,andsum&a[i]);
		}
		cout<<anss;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				anss=max(anss,a[i]&a[j]);
			}
		}
		cout<<anss;
		return 0;
	}
	andsum=a[n];
	m-=1;
	int i=n-1;
	while(m>0)
	{
		andsum&=a[i];
		m--;
		i--;
	}
	cout<<andsum;
	return 0;
}
