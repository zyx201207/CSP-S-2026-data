#include<bits/stdc++.h>
using namespace std;
int a[1000005],f[1000005],b[1000005],x[1000005];
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
			f[a[j]]++;
			b[a[j]]++;
			if(f[a[j]]==1)
			{
				
				x[a[j]]=j;
			}
			else if(f[a[j]]>1)
			{
				f[a[j]]=1;
				for(int k=x[a[j]]+1;k<=j;k++)
				{
					b[a[k]]--;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			f[j]=0;
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}

                                              
