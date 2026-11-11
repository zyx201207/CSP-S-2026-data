#include<bits/stdc++.h>
using namespace std;
#define M 50050
#define N 550
int q[M];
int o[M];//第M个站是不是换乘车站 
int v[M];
int x,y;
int ans;
struct abc
{
	int b[M];//第i个站是那个站 
	int f[M];//第i个站费用 
	int k;//K个站 
}a[N];//第ai条地铁线
struct abcd
{
	int k1;//这个地铁站经过k1条线
	int e[N];//第ej条地铁线是那条线 
	int ff[N];//上第i条地铁的费用 
}z[M];//第ai地铁站 
int F(int a1,int a2,int aa)
{
	int f1=0,f2=0;
	for(int i=1;i<=a[aa].k;i++)
	  {
	  	if(a[aa].b[i]==a1)
	  	  f1=1;
	  	else if(a[aa].b[i]==a2)
	  	  f2=1;
	  }
	if(f1==1&&f2==1)
	  return 1;
	return 0;
}
void find(int now,int fy)//目前在x车站 ,目前的费用为f 
{
	if(fy>ans)
	  return ;
	for(int i=1;i<=z[now].k1;i++)//找这个站上的每一条线 
	  {
	  	int t=z[now].e[i];//这条线的编号是t 
	  	if(F(now,y,t)==1)//两个车站是不是都在这条线上 
	  	  {
	  	  	ans=min(ans,fy+z[now].ff[t]+z[y].ff[t]);
	  	  	return;
		  } 
		else
		  {
		  	for(int j=1;j<=a[t].k;j++)//访问每一个站，注意换乘站 
		  	  {
		  	  	int zhan=a[t].b[j];
		  	  	if(o[zhan]==0||v[zhan]==1)
			      continue; 
			    v[zhan]=1;
			    find(zhan,fy+z[now].ff[t]+z[zhan].ff[t]);
			    v[zhan]=0;
			  }
		  }
	  }
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qq;
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	  cin>>q[i];
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i].k;
	  	for(int j=1;j<=a[i].k;j++)
	  	  {
	  	  	cin>>a[i].b[j];
	  	  	cin>>a[i].f[j];
	  	  	z[a[i].b[j]].k1++;
			z[a[i].b[j]].e[z[a[i].b[j]].k1]=i;
			z[a[i].b[j]].ff[i]=a[i].f[j];
		  }
	  }
	for(int i=1;i<=m;i++)
	  if(z[i].k1>1)
	    o[i]=1;
	/*for(int i=1;i<=m;i++)
	  if(o[i]==1)
	    cout<<i<<" ";
	cout<<endl;*/
	for(int i=1;i<=qq;i++)
	  {
	  	for(int i=1;i<=m;i++)
	  	  v[i]=0;
	  	cin>>x>>y;
		v[x]=1;
		ans=0x3f3f3f3f;
	  	find(x,0);
	  	cout<<ans+q[x]+q[y]<<endl;
	  }
	return 0;
}
