#include <iostream>
#include <cstdio>
using namespace std;
int a[500005],c[500005];
bool b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				b[a[j]]=true;
			}
			else
			{
				for(int k=j-1;k>=i;k--)
				{
					if(b[a[k]]&&a[k]==a[j]&&k!=j)
					{
						break;
					}
					b[a[k]]=false;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j])
			{
				c[j]++;
				b[j]=false;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
 } 
