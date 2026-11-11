#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int M=600000,N=500;
const long long inf=1000000000000;
int w[M];
vector<pair<int,int> >s[M];
long long dis[N][N];
void cmin(long long&x,long long y)
{
	if (x>y) x=y;
}
int read()
{
	char x;
	int i;
	do x=getchar();
	while (x<'0'||x>'9');
	for (i=0;x>='0'&&x<='9';x=getchar()) i=i*10-'0'+x;
	return i;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,k,x,y,j,siz1,l,siz2;
	long long ans;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (i=1;i<=m;i++) w[i]=read();
	for (i=0;i<n;i++) for (k=read();k;k--)
	{
		x=read();
		y=read(); 
		s[x].push_back(make_pair(i,y));
	}
	for (i=0;i<n;i++) for (j=0;j<n;j++) dis[i][j]=inf;
	for (i=0;i<n;i++) dis[i][i]=0;
	for (i=1;i<=m;i++)
	{
		siz1=s[i].size();
		for (j=0;j<siz1;j++) for (l=0;l<siz1;l++) cmin(dis[s[i][j].first][s[i][l].first],s[i][j].second+s[i][l].second);
	}
	for (i=0;i<n;i++) for (j=0;j<n;j++) for (l=0;l<n;l++) cmin(dis[j][l],dis[j][i]+dis[i][l]);
	for (;q;q--)
	{
		x=read();
		y=read();
		siz1=s[x].size();
		siz2=s[y].size();
		ans=inf;
		for (i=0;i<siz1;i++) for (j=0;j<siz2;j++) cmin(ans,dis[s[x][i].first][s[y][j].first]+s[x][i].second+s[y][j].second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
