#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[300001],c[500001],d[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				c[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long x=i;
		for(int j=1;j<=m;j++) d[j]=0;
		while(x<=n)
		{
			if(d[a[x]]==0)
			{
				b[a[x]]++;
				d[a[x]]=1;
			}
			if(c[x]!=0) x=c[x];
			else x++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

