#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int t[200010];
int w[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(w[b[j]]==0)
			{
				a[j]=b[j];
				w[b[j]]=j;
			}
			else
			{
				for(int h=w[b[j]]+1;h<=j;h++)
				{
				    w[a[h]]=0;
					a[h]=0;
					
				}
			}
			
		}
		for(int j=i;j<=n;j++)
		{
			t[a[j]]++;
		}
		for(int j=1;j<=n;j++)
		{
			a[j]=0;
		
		}
		for(int j=1;j<=m;j++)
		{
			w[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
