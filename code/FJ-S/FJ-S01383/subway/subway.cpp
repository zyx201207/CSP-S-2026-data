#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[511111],k,a[511111],t[511][511],b[511][511],x,y,minn=111111111,f[511][511],u[511][511],g[511111],ttt,v;
void man(int xx,int tt,int kk,int e)
{
	if(xx==y)
	{
		tt=tt+t[kk][xx];
		if(tt<=minn)
		{
			minn=tt;
		}
		return;
	}
	if(e==0)//Õ¾Ìü 
	{
		for(int j=1;j<=n;j++)
		{
			if(u[j][xx]==1&&g[xx]==0)
			{
				g[xx]=1;
				v=tt+t[j][xx];
				man(xx,v,j,1);
				g[xx]=0;
			}
		}
	}
	if(e==1)//Õ¾Ì¨ 
	for(int j=1;j<=m;j++)
	{
		if(b[xx][j]==kk&&f[xx][j]==0)
		{
			f[xx][j]=1;
			f[j][xx]=1;
			man(j,tt,kk,1);
			f[xx][j]=0;
			f[j][xx]=0;
		}
	}
	if(e==1&&g[xx]==0) man(xx,tt+t[kk][xx],0,0);
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>ttt;
			t[i][a[j]]=ttt;
			u[i][a[j]]=1;
		}
		for(int j=1;j<=k-1;j++)
		{
			b[a[j]][a[j+1]]=i;
			b[a[j+1]][a[j]]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		minn=111111111;
		man(x,0,0,0);
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
