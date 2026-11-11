#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
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
int n,d,a[N],R[N],sum[N],w[N];
bool vis[N];
vector<int>g[N];
void dfs(int u,int fa){for(int v:g[u]) if(v!=fa) dfs(v,u),w[u]+=sum[v];sum[u]+=w[u];}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear(),vis[i]=0,sum[i]=R[i]=w[i]=0;
	for(int i=1,j=0;i<=n;i++)
	{
		while(j<n&&a[j+1]<=a[i]+d) j++;
		R[i]=j;
//		cout<<R[i]<<' ';
	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j!=R[j]&&!vis[j])
		{
			g[j].push_back(R[j]);
			g[R[j]].push_back(j);
			vis[j]=1;
			j=R[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=R[i]) sum[i]++;
		vis[i]=0;
//		cout<<R[i]<<" +1"<<endl;
	}
//	cout<<"===="<<endl;
	for(int i=1;i<=n;i++) if(i==R[i]) dfs(i,0);
//	for(int i=1;i<=n;i++) cout<<w[i]<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(R[i]-i<=1||vis[R[i]]) continue;
		vis[R[i]]=1;
//		cout<<i<<' '<<R[i]<<' '<<R[i]-1<<": "<<endl;
//		cout<<"v: ";
//		for(int j=max(R[R[i]-2],R[i])+1;j<=R[R[i]-1];j++) cout<<j<<' ';
//		cout<<endl;
//		cout<<"cnt(u): "<<w[R[i]]<<endl; 
//		cout<<"------"<<endl; 
		ans+=1ll*w[R[i]]*max(0ll,R[R[i]-1]-max(R[R[i]-2],R[i]));
	}
	cout<<ans<<endl;
//	cout<<"=======Finished======="<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int id,T;
	cin>>id>>T;
	while(T--) solve();
	return 0;
}

