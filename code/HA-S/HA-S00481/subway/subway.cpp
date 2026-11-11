#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int myread()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void prin(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) prin(x/10);
	putchar(x%10+'0');
}

const int MAXN=505,MAXM=500005,MAXD=22;
const ll INF=1000000000000000000;

int c,n,m,d,q;
int w[MAXM];
int to[MAXM][MAXD];
int val[MAXM][MAXD];
int cnt[MAXM];

ll dis[MAXN][MAXN];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=myread(); n=myread(); m=myread(); d=myread(); q=myread();
	for (int i=1;i<=m;i++) w[i]=myread();
	for (int i=1,k;i<=n;i++)
	{
		k=myread();
		int a,t;
		while (k--)
		{
			a=myread(); t=myread();
			cnt[a]++;
			to[a][cnt[a]]=i;
			val[a][cnt[a]]=t;
		}
	}
	
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int u=1;u<=m;u++)
	{
		for (int i=1;i<=cnt[u];i++)
		{
			for (int j=i+1;j<=cnt[u];j++)
			{
				int x=to[u][i],y=to[u][j];
				dis[x][y]=dis[y][x]=min(dis[x][y],(ll)(val[u][i])+val[u][j]);
			}
		}
	}
	
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	int x,y;
	while (q--)
	{
		x=myread(); y=myread();
		ll ans=INF;
		for (int i=1;i<=cnt[x];i++)
		{
			for (int j=1;j<=cnt[y];j++)
			{
				ans=min(ans,dis[to[x][i]][to[y][j]]+val[x][i]+val[y][j]);
			}
		}
		ans+=(ll)(w[x])+w[y];
		prin(ans);
		putchar('\n');
	}
	
	return 0;
}
