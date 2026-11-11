#include<bits/stdc++.h>
namespace LMY{
	using std::min;
	using std::max;
	using std::pair;
	#define int long long
	#define pii pair<int,int>
	#define pip pair<int,pii>
	#define ppi pair<pii,int>
	#define ppp pair<pii,pii>
	#define lp first
	#define rp second
	#define edl putchar('\n')
	#define lowbit(x) ((x)&(-(x)))
	constexpr int inf=0x1f1f1f1f1f1f1f1f;
	int read()
	{
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		return f*x;
	}
	void write(int x)
	{
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void print(int x,char ed='\n'){write(x);putchar(ed);}
	constexpr int N=500+10,M=5*1e5+100,P=1e9+7;
	int cid,n,m,d,q,w[M],dis[N][N];
	std::vector<pii> G[M];
	signed Main()
	{
		cid=read(),n=read(),m=read(),d=read(),q=read();
		for(int i=1;i<=m;i++) w[i]=read();
		for(int i=1;i<=n;i++)
		{
			for(int k=read();k--;)
			{
				int a=read(),t=read();
				G[a].push_back({i,t});
			}
		}
		memset(dis,0x1f,sizeof(dis));
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=m;i++) for(pii e1:G[i]) for(pii e2:G[i])
			dis[e1.lp][e2.lp]=min(dis[e1.lp][e2.lp],e1.rp+e2.rp);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		while(q--)
		{
			int x=read(),y=read(),ans=inf;
			for(pii e1:G[x]) for(pii e2:G[y])
				ans=min(ans,e1.rp+e2.rp+dis[e1.lp][e2.lp]);
			print(ans+w[x]+w[y]);
		}
		return 0;
	}
}
signed main()
{
//	system("fc subway.out subway.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return LMY::Main();
}
//Time Complexity: O(n^3+m*d+n*d^2)
