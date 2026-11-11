#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000+10],dp[10000+10]; 
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal. out","r",stdout);
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
		if(dp[z]>m)
		{
			i++;
			j=i+1;
			z=1;
		}
	    else if(dp[z]+dp[z-1]==m)
	    {
	    	cout<<j;
		}
		j++;
		z++;
	}
	return 0;
 } 
 
 /*
 i    j
 1 2 4 8 9
 dp[1]
  i    j
-3 -1 2 2 7
 */
