#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], f[500005];
int v[50005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool w=0;
			for(int k=1;k<j;k++)
			{
				if(f[k]==a[j])
				{
					for(int h=k+1;h<=j;h++)
					{
						f[h]=0;
					}
					w=1;
					break;
				}	
			}
			if(!w)
			{
				f[j]=a[j];
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(f[k]=j)
				{
					v[j]++;
					break;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			f[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0; 
 }
