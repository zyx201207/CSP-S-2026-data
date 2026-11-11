#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long dp1[200010];
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
	
	for(int i=0;i<=31;i++)
	{
		dp1[0]+=pow(2,i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp1[j]=max(dp1[j],dp1[j-1]&a[i]);
		
		}
		
	}
	cout<<dp1[m];
	return 0; 
}
