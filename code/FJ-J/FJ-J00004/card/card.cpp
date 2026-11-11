#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int o=0,t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int f=0;
			for(int x=1;x<=n;x++)
			{
				if(x!=j)
				{
					if(a[x]==a[j])
					{
						f++;
					}
				}
			}
			if(f<=1)
			{
				for(int x=j;x<n;x++)
				{
					a[x]=a[x+1];
				}
				a[n]=a[j];
			}
			else
			{
				int ii;
				for(int x=1;x<=n;x++)
				{
					if(a[x]==a[j]&&x!=j)
					{
						ii=x;
						break;
					}
				}
				n=ii;
				for(int x=j;x<n;x++)
				{
					a[x]=a[x+1];
				}
				a[n]=a[j];
			 } 
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]==1)
			{
				o++;
			}
			else
			{
				t++;
			}
		}
	}
	cout << o << " " << t;
	return 0;
}
