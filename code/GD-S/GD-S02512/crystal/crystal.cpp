#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],c;

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
	int i;
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			c=0;
			for(int k=j;k<j+i;k++)
			{
				c+=a[j+i]-a[k];
				if(c>m)
				{
					break;
				}
			}
			if(c<=m)
			{
				break; 
			}
		}
		if(c>m)
		{
			break;
		}
	}
	cout<<i;
	return 0;
}
