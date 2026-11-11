#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],c[500001],y,c2[500001],p[500001];
long long f[3001][5001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
		f[a[i]][c[a[i]]]=i;
	} 
	for(int z=1;z<=n;z++)
	{
		for(int i=1;i<z;i++) c2[a[i]]++;
		for(int i=z;i<=n;i++)
		{
			c2[a[i]]++;
			if(i<y) continue;
			if(f[a[i]][c2[a[i]]+1]==0) p[a[i]]++;
			if(f[a[i]][c2[a[i]]+1]!=0)
			{
				y=f[a[i]][c2[a[i]]+1];
			}
		}
		memset(c2,0,sizeof(c2));
		y=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<p[i]<<" ";
	}
}
