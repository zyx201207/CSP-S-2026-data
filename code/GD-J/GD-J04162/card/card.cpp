#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			if(a[i]==a[j])
			{
				for(int o=j+1;o<=i;o++)
				{
					a[o]=0;
				}
				break;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			cout<<a[i];
		}
		else
		{
			
			return 0;
		}
	}
	
}
