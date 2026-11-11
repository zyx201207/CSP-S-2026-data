#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],d[500005],h[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{		
		cin>>a[i];
		h[a[i]]=i;
	}
	/*if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(!b[a[j]])
					b[a[j]]++,c[++l]=a[j];
				else
					while(c[l]!=a[j])
						b[c[l]]--,c[l]=0,l--;
			}	
			for(int j=1;j<=l;j++)
				d[c[j]]++;
			for(int i=1;i<=5000;i++)
				b[i]=c[i]=0;
			l=0;
		}
		for(int i=1;i<=m;i++)
			cout<<d[i]<<" ";
		return 0;
	} 
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			b[a[i]]++,b[a[i]^3]+=(a[i]!=a[n]);
		for(int i=1;i<=m;i++)
			cout<<b[i]<<" ";
		return 0;
	}
	if(xzb<=5000)
	{
		int k=1;
		b[k]=a[1],c[k]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==b[k])
				c[k]++;
			else
				b[++k]=a[i],c[k]=1;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=i;j<=k;j++)
			{
				if(!e[b[j]])
					e[b[j]]++,f[++l]=b[j],g[l]=c[j];
				else
					while(f[l]!=b[j])
						e[f[l]]--,f[l]=0,g[l]=0,l--;
			}	
			for(int j=1;j<=l;j++)
				d[f[j]]+=g[1];
			for(int i=1;i<=5000;i++)
				e[i]=f[i]=0;
			l=0;
		}
		for(int i=1;i<=m;i++)
			cout<<d[i]<<" ";
		return 0;
	}*/
	for(int i=1;i<=n;i++)
	{
		int b=i;
		while(b<=n)
		{
			d[a[b]]++,b=h[a[b]]+1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<d[i]<<" ";
	return 0;
}

