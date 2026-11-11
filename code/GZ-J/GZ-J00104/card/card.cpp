//GZ-J00104 贵州省瓮安第二中学 严云涵 
#include <bits/stdc++.h>
using namespace std;
int a[5005],b[5005],c[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
		}
		for(int x=1;x<=m;x++)
		{
			if(b[x]>1)
			{
				for(int y=n-1;y>=i;y--)
				{
					if(a[y]==x)
					{
						for(int z=1;z<y;z++)
						{
							if(b[a[z]]-1>=0)
							{
								b[a[z]]--;
							}
							
						}
					}
				}
			}
		}
		for (int j=1;j<=m;j++)
		{
			c[j]+=b[j];
			c[a[n]]=n;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
