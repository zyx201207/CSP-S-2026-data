#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,d,q,w[500005],dis[1005][1005];
struct Line
{
	int ki;
	vector<int>aij;
	vector<int>tij;
}li[1005];
int read()
{
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0'); 
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
		dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		li[i].ki=read();
		int cs=0;
		for(int j=1;j<=li[i].ki;j++)
		{
			cs=read();
			li[i].aij.push_back(cs);
			cs=read();
			li[i].tij.push_back(cs);
		}
		for(int j=0;j<li[i].ki;j++)
			for(int k=0;k<li[i].ki;k++)
				dis[li[i].aij[j]][li[i].aij[k]]=li[i].tij[j]+li[i].tij[k];
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	while(q--)
	{
		int x,y;
		x=read(),y=read();
		write(w[x]+dis[x][y]+w[y]);
		cout<<'\n';
	}
}
