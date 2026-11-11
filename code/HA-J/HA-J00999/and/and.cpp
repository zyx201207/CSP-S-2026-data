#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,x,y;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>a[1];int i,j;
	x=a[1];
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		x=x^a[i];
		if(a[i]>y) y=a[i];
	}
	if(m==n)
	cout<<x;
	if(m==1)
	cout<<y;
	if(m==n-1)
	{
		for(i=1;i<=n;i++)
		if(x^a[i]>maxx) maxx=x^a[i];
		cout<<maxx;
	}
	if(m==2)
	{
		for(i=1;i<n;i++)
		for(j=i;j<=n;j++)
		{
			if(a[i]^a[j]>maxx)
			maxx=a[i]^a[j];
		}
		cout<<maxx;
	}
	return 0;
}