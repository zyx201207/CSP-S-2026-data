#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	long long a[20005];
	long long m;
	long long maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];

		
	}
	
		for(int j=1;j<=n;j++)
		{
			
		
			for(int k=j+1;k<=n;k++)
			{
				long long c=a[j];
				for(int i=0;i<m-1;i++)
				{
					c=c&a[k+i];
					
				}
				
				maxn=max(maxn,c);
				
			}
			
			
			
		}
		cout<<maxn;

	
	return 0;
}
