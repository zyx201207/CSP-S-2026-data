#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crytsal.out","w",stdout);
	 	cin>>n>>m;
	 for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=2,z=1;
	dp[1]=a[2]-a[1]; 
	while(j<=n)
	{
		dp[z]=a[j]-a[i];
		j++;
		if(dp[z]>m)
		{
			i++; 
		}
	    else if(dp[z]==m)
	    {
	    	cout<<z+1;
		}
	}
	return 0;
 } 
 
  
