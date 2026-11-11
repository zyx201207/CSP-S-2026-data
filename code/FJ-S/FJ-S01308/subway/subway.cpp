//廝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP RP++

#include<bits/stdc++.h>
using namespace std;

//#define write ios::sync_with_stdio(0);
//#define by cin.tie(0);
//#define __wanghc__ cout.tie(0);

//#define ll long long

const int N=2e4+10;
int c,n,m,d,q;
int w[N];
struct Subway{
	int k;
	int a[N],t[N];
}sub[505];
int g[N][N];

inline int read()
{
	char ch=getchar();
	int f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	int x=0;
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int main()
{

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		cin>>sub[i].k;
		for(int j=1;j<=sub[i].k;j++)
			sub[i].a[j]=read(),sub[i].t[j]=read();
	}
	
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++) g[i][i]=0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sub[i].k;j++)
			for(int k=j+1;k<=sub[i].k;k++)
				g[sub[i].a[j]][sub[i].a[k]]=g[sub[i].a[k]][sub[i].a[j]]=sub[i].t[j]+sub[i].t[k];

	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=m;k++)
			{
				if((k==i || k==j) || (g[i][k]==0x3f3f3f3f || g[k][j]==0x3f3f3f3f))
					continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}	
		}
				
	for(int i=1;i<=q;i++)
	{
		int start,end;
		cin>>start>>end;
		int ans=w[start]+w[end]+g[start][end];
		cout<<ans<<endl;
	}	
	return 0;
}

//	write by __wanghc__
