#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
void write(long long x)
{
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
struct node
{
	long long li,ti;
};
long long min(long long x,long long y)
{
	return x<y?x:y;
}
long long type,n,m,d,q,w[500005],f[505][505];
vector<node>a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	type=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
		for(int t=1;t<=n;++t)
			if(i!=t)
				f[i][t]=1e18;
	for(int i=1;i<=n;++i)
	{
		long long len;
		len=read();
		for(int t=1;t<=len;++t)
		{
			long long x,y;
			x=read();
			y=read();
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;++i)
		for(int t=0;t<(int)a[i].size();++t)
			for(int j=t+1;j<(int)a[i].size();++j)
			{
				f[a[i][t].li][a[i][j].li]=min(f[a[i][t].li][a[i][j].li],a[i][t].ti+a[i][j].ti);
				f[a[i][j].li][a[i][t].li]=min(f[a[i][j].li][a[i][t].li],a[i][t].ti+a[i][j].ti);
			}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int t=1;t<=n;++t)
				f[i][t]=min(f[i][t],f[i][k]+f[k][t]);
	while(q--)
	{
		long long x,y,ans=1e18;
		x=read();
		y=read();
		for(auto i:a[x])
			for(auto t:a[y])
				ans=min(ans,w[x]+i.ti+f[i.li][t.li]+t.ti+w[y]);
		write(ans);
		putchar('\n');
	}
	return 0;
}
