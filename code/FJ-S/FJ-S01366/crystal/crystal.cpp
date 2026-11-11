#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],maxx=-1;
int s(int x)
{
	int sum=0,r=0;
	for(int i=1;i<=x;i++)
	{
		b[i]=a[x]-a[i];
	}
	for(int i=1;i<=x;i++)
	{
		if(b[i]+r<=m)
		{
			r+=b[i];
			sum++;
		}
	}
	return sum;
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(maxx<s(i))
		{
			maxx=s(i);
		}
	}
	cout<<maxx;
	return 0;
 } 
