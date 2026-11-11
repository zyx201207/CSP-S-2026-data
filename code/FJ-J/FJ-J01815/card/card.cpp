#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
bool f[10000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("card.in","r",stdin);
	/ /freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(c[k]==a[j])
				{
					for(int x=k;x<=n;x++)
					{
						c[x]=0;
						
					}
					c[k]=a[j];
					break;
				}
				if(c[k]==0)
				{
					c[k]=a[j];
					break;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(c[j]!=0)
			{
				if(f[c[j]]!=0)b[c[j]]++;
				f[c[j]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
	}
	return 0;
}
