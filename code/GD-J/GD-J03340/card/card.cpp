#include <bits/stdc++.h>
using namespace std;

int a[500000]={0},b[500000]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n=0,m=0;
	cin>>n>>m;
	bool t=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int p=1;p<=n;p++)
	{
		for(int i=p;i<=n;i++)
		{
			for(int j=p;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				else if(a[i]==a[j])
				{
					t=0;
					for(int k=1;k<=n;k++)
					{
						if(k>=i&&k<j)
						{
							continue;
						}
						else
						{
							b[a[k]]=b[a[k]]+1;
							break;
						}
					}
				}
				break;
			}
			if(t)
			{
				for(int x=p;x<=n;x++)
				{
					b[a[x]]=b[a[x]]+1;
				}
			}
		}
	}
	
	for(int y=1;y<=m;y++)
	{
		cout<<b[y]<<" ";
	}
	return 0;
}
