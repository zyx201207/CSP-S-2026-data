#include<bits/stdc++.h>
using namespace std;
const int B=550;
int n,m,cnt,g,h[300005],a[500005],an[300005],u[300005],uu[300005],z[300005];
int d[300005],q[300005],e[300005];
int b[B+5][300005],bb[B+5],c[300005],cc[B+5];
struct bian{int n,d;}bn[300005];
void hi(int x,int y)
{
	cnt=0;
	for(int i=y;i<=n;i++)
	{
		if(!uu[a[i]])z[++cnt]=a[i],uu[a[i]]=1;
		else while(z[cnt]!=a[i])uu[z[cnt--]]=0;
	}
	bb[x]=cnt;
	for(int i=1;i<=cnt;i++)b[x][i]=z[i],uu[z[i]]=0;
}
void hello(int x)
{
	for(int i=h[x];i;i=bn[i].n)
	{
		hello(bn[i].d);
		e[x]=max(e[x],e[bn[i].d]+1);
	}
	if(e[x]==B||x==a[n])
	{
		q[x]=0,d[x]=++g;
		hi(g,u[x]);
		e[x]=-1;
	}
}
void hey(int x,int y)
{
	if(!q[x])y=d[x];
	d[x]=y;
	for(int i=h[x];i;i=bn[i].n)hey(bn[i].d,y);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(u[a[i]])continue;
		u[a[i]]=i,q[a[i]]=a[i+1];
		if(i<n)bn[a[i]]={h[a[i+1]],a[i]},h[a[i+1]]=a[i];
	}
	hello(a[n]);
	hey(a[n],0); 
	for(int i=n;i>=1;i--)cc[d[a[i]]]++,c[a[i]]++;
	for(int i=1;i<=g;i++)for(int j=1;j<=bb[i];j++)an[b[i][j]]+=cc[i];
	for(int i=1,j;i<=m;i++)
	{
		j=i;
		while(q[j])an[j]+=c[i],j=q[j];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<an[i]<<' ';
	}
	return 0;
}
