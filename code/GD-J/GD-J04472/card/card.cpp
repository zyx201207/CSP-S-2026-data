#include<bits/stdc++.h>
using namespace std;
long long a[1000005],dis[1000005];
bool f[1000005];
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
		for(int j=1;j<=m;j++)
		{
			f[j]=false;
		}
		for(int j=i;j<=n;j++)
		{
			
			if(f[a[j]]==true)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[k]==a[j])
					{
					
						dis[a[j]]--;
						break;
					}
					if(f[a[k]]==false)
					{
						continue;
					}
					f[a[k]]=false;
					dis[a[k]]--;
				}
								
				dis[a[j]]++;
			}
			else
			{
//				cout<<dis[a[j]]<<" "; 
				dis[a[j]]++;

				f[a[j]]=true;
			}
		}
	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dis[i]<<" ";
	}
	return 0;
}
