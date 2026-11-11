#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int sum[10001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	    	if(a[i]==a[j])
	    	{ 
	    		sum[i]++;
	    		continue;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(sum[i]==0)
		{
			continue;
		}
		else if(sum[i]>0)
		{
			cout<<sum[i]<<" ";
		}
		else
		{
			return 0;
		}
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
}
