#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif

inline ll read()
{
	ll x=0,f=1;
	char ch=' ';
	while (!isdigit(ch))
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void prt(ll x)
{
	if (x>0)
	{
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	else if (x==0) putchar('0');
	else
	{
		putchar('-');
		x=-x;
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	return;
}

const int maxn=500+10,maxm=5e5+10;
const ll INF=4e18;

using pill=pair<int,ll>;

int C,n,m,d,Q,k,x,y;
ll ans;
ll ground_to_hall[maxm],line_to_line[maxn][maxn];
vector<pill>hall_to_platform[maxm];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	C=read(),n=read(),m=read(),d=read(),Q=read();
	for (int i=1;i<=m;i++)
	{
		ground_to_hall[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		k=read();
		for (int j=1;j<=k;j++)
		{
			int a=read();
			ll t=read();
			hall_to_platform[a].push_back({i,t});
		}
	}
	memset(line_to_line,0x3f,sizeof(line_to_line));
	for (int i=1;i<=n;i++)
	{
		line_to_line[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		int J=hall_to_platform[i].size();
		for (int j1=0;j1<J;j1++)
		{
			auto P=hall_to_platform[i][j1];
			for (int j2=j1+1;j2<J;j2++)
			{
				auto Q=hall_to_platform[i][j2];
				line_to_line[P.first][Q.first]
					=min(line_to_line[P.first][Q.first],P.second+Q.second);
				line_to_line[Q.first][P.first]
					=min(line_to_line[Q.first][P.first],Q.second+P.second);
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				line_to_line[i][j]=min(line_to_line[i][j],line_to_line[i][k]+line_to_line[k][j]);
			}
		}
	}
	while (Q--)
	{
		x=read(),y=read();
		ans=INF;
		for (auto P:hall_to_platform[x])
		{
			for (auto Q:hall_to_platform[y])
			{
				ans=min(ans,line_to_line[P.first][Q.first]+P.second+Q.second);
			}
		}
		ans+=ground_to_hall[x]+ground_to_hall[y];
		prt(ans),putchar('\n');
	}
	
	return 0;
}
