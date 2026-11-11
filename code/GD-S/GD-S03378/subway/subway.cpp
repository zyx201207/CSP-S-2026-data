#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],f[505][505];
vector<pair<long long,long long> >edge[500005];
void read(long long &x)
{
	x=0;
	int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1; 
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=w;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	int top=0,sta[100];
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top--) putchar(sta[top]+'0');
	putchar('\n');
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q); 
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++)
	{
		long long k,v,ww;
		read(k);
		while(k--)
		{
			read(v);read(ww);
			edge[v].push_back({i,ww});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int ii=0;ii<(int)edge[i].size();ii++)
		{
			for(int jj=ii+1;jj<(int)edge[i].size();jj++)
			{
				f[edge[i][ii].first][edge[i][jj].first]=f[edge[i][jj].first][edge[i][ii].first]=min(f[edge[i][jj].first][edge[i][ii].first],edge[i][ii].second+edge[i][jj].second);
			}
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i][k]==1e18) continue;
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
		}
	}
	long long u,v;
	while(q--)
	{
		read(u);read(v);
		long long ans=1e18;
		for(pair<long long,long long> vv:edge[u])
		{
			for(pair<long long,long long> vv1:edge[v])
			{
				ans=min(ans,f[vv.first][vv1.first]+vv.second+vv1.second);
			}
		}
		write(ans+w[u]+w[v]);
	}
	return 0;
 } 
