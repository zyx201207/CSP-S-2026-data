#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e7+5;
long long a[N],b[N]={0},c[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=i;j<n;j++)
		{
			if(j!=0)
			{
				for(int x=j-1;x>=i;x--)
				{
					if(a[j]==a[x])
					{
						for(int x=j-1;x>=i;x--)
						{
							a[x]=0;
						}
						break;
					}
				}
			}
		}
		
		for(int j=i;j<n;j++)
		{
			b[a[j]]++;
		}
		for(int j=0;j<n;j++)
		{
			a[j]=c[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
