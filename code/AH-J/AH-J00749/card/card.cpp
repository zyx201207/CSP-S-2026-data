#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool vis[500005];
long long a[500005],b[500005],c[500005],s[500005],p[500005],t[500005];
int main(void)
{
	//card
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[j-i+1]=a[j];
		}
		for(int j=1;j<=n-i+1;j++)
		{
			if(vis[b[j]]==0)
			{
				vis[b[j]]=1;
				p[b[j]]=j;
			}
			else
			{
				c[j]++;
				c[p[b[j]]]--;
				for(int u=p[b[j]];u<=j-1;u++)
				{
					vis[b[u]]=0;
				}
				vis[b[j]]=1;
				p[b[j]]=j;
			}
		}
		c[1]++;
		for(int j=1;j<=n-i+1;j++)
		{
			s[j]=s[j-1]+c[j];
		}
		for(int j=1;j<=n-i+1;j++)
		{	
			t[b[j]]+=s[j];
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
			c[j]=0;
			p[j]=0;
			s[j]=0;
		}
		for(int j=1;j<=m;j++)
		{
			vis[j]=0;
			p[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
