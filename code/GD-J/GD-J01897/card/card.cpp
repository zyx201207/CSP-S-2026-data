#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	long long n,m;
	cin>>n>>m;
	long long a[n+1],b[300000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	long long c[n+1],hj=0;
	for(int i=1;i<=n;i++)
	{
		hj=0;
		for(int j=i;j<=n;j++)
		{
			c[j]=a[j];
			if(j>1)
			{
				for(int o=j-1;o<=1;o--)
				{
					if(c[j]==c[o])
					{
						hj=j;
					}
				}
			}
		}
	    
	
		for(int j=hj;j<=n;j++)
		{
			b[c[j]]++;
		}
		if(hj>0)
		{
		
		for(int j=hj;i>i;i--)
		{
			a[j]=a[j-1];
		}
	    }
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	
	return 0;
}
