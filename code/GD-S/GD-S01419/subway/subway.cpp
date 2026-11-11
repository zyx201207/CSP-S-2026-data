#include <bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=510,M=5e5+10;
namespace FastIO
{
	const int SIZE=(1<<21)+1;
	char c,ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=obuf+SIZE-1,qu[55];
	int f,qr;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
	template<class I=int>inline I read() {for(f=1,c=gc();c<'0'||c>'9';c=gc()) if(c=='-') f=-1;I x=0;for(;c>='0'&&c<='9';c=gc()) x=(x<<(I)3)+(x<<(I)1)+(c&15);return x*f;}
	inline void putc(char x){if(oS==oT) {fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}*oS++=x;}
	template<class I=int>inline void print(I x){if(!x) putc('0');if(x<0) putc('-'),x=-x;while(x) qu[++qr]=(x%10)+'0',x/=10;while(qr) putc(qu[qr--]);}
	struct Flusher_{~Flusher_(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}}io_flusher_; 
};
int c,n,m,d,q,w[M],dis[N][N];
vector<pi>line[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int u,t;
			cin>>u>>t;
			line[u].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=dis[j][i]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) for(int s=0;s<line[i].size();s++) for(int t=s+1;t<line[i].size();t++)
	{
		int u=line[i][s].fi,v=line[i][t].fi;
		dis[u][v]=dis[v][u]=line[i][s].se+line[i][t].se;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(pi i:line[x]) for(pi j:line[y]) ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

