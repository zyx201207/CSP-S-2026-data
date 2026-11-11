#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],f[600000],p[600000],g[6000000];
deque<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		long long y=0;
		for(int j=1;j<=n;j++)
		{
			p[j]=g[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(g[a[j]]==0)
			{
				p[++y]=a[j];
				g[a[j]]=1;
			}
			else
			{
				while(p[y]!=a[j])
				{
					g[p[y]]=0;
					p[y]=0;
					y--;
				}
				
			}
		}
		
		for(int j=1;j<=y;j++)
		{
			f[p[j]]++;
		}
	}
	for(int j=1;j<=n;j++)
	{
		p[j]=g[j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
