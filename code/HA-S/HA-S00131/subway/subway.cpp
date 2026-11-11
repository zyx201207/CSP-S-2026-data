#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pir pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int re()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
template<typename T> inline void chkmin(T &a,T b){a=min(a,b);}
template<typename T> inline void chkmax(T &a,T b){a=max(a,b);}
const int N=510,M=500010,D=22;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,n,m,d,q;
int w[M];
int bx[M][D],t[M][D],cntx[M];
ll g[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=re();n=re();m=re();d=re();q=re();
	for(int i=1;i<=m;i++) w[i]=re();
	for(int i=1;i<=n;i++)
	{
		int k=re();
		for(int j=1;j<=k;j++)
		{
			int pos=re(),ti=re();
			cntx[pos]++;
			bx[pos][cntx[pos]]=i;
			t[pos][cntx[pos]]=ti;
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cntx[i];j++) for(int k=1;k<=cntx[i];k++) if(j^k)
			chkmin(g[bx[i][j]][bx[i][k]],(ll)(t[i][j]+t[i][k]));
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(g[i][k]<INF) for(int j=1;j<=n;j++)
		chkmin(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=q;i++)
	{
		int x=re(),y=re();
		ll ans=INF;
		for(int j=1;j<=cntx[x];j++) for(int k=1;k<=cntx[y];k++)
			chkmin(ans,g[bx[x][j]][bx[y][k]]+w[x]+w[y]+t[x][j]+t[y][k]);
		printf("%lld\n",ans);
	}
	return 0;
}
