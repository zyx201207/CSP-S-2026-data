#include<bits/stdc++.h>
using namespace std;
int d2[500005],d[500005],dp[500005],a[500005],d1[500005],l[500005],d3[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		int xa=a[i];
		if(d[xa]==0)
		{
			d[xa]=1;
			d3[i]=1;
		}
		else d1[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+d1[i];
		if(d3[i]==1)
		{
			l[a[i]]=i-(dp[i]-d2[a[i]]);
		}
		d2[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=a[n])cout<<l[i]<<" ";
		else cout<<n<<" "; 
	}
	return 0; 
 } 

