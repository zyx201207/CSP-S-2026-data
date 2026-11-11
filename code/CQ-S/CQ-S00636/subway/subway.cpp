#include<bits/stdc++.h>
using namespace std;
char BEGIN;
namespace hwq{
	#define ll long long
	char buf[1<<21],*_S,*_T;
	#define gc (_S==_T&&(_T=(_S=buf)+fread(buf,1,1<<21,stdin),_S==_T)?EOF:(*_S++))
	inline ll read(){ll x=0;bool f=0;char ch=gc;while(!isdigit(ch)&&ch!='-') ch=gc;if(ch=='-') f=1,ch=gc;while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=gc;return f?-x:x;}
	const int MAXN=5e5+5;
	const ll INF=1e18+5;
	auto chn=[](ll &x,const ll &k){x>k&&(x=k);};
	int c,n,m,d,q;
	int bel[MAXN][21],t[MAXN][21],p[MAXN];
	ll w[MAXN],dis[505][505];
	int main(){
		c=read(),n=read(),m=read(),d=read(),q=read();
		for(int i=1;i<=m;i++) w[i]=read();
		for(int i=1;i<=n;i++){
			int k=read(),x;
			while(k--)
				x=read(),bel[x][++p[x]]=i,t[x][p[x]]=read();
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=i==j?0:INF;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=p[i];j++)
				for(int k=j+1;k<=p[i];k++)
					chn(dis[bel[i][j]][bel[i][k]],t[i][j]+t[i][k]),
					chn(dis[bel[i][k]][bel[i][j]],t[i][j]+t[i][k]);
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++) 
//				printf("dis[%d][%d]=%lld\n",i,j,dis[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					chn(dis[j][k],dis[j][i]+dis[i][k]);
		int x,y;
		while(q--){
			x=read(),y=read();
			ll ans=INF;
			for(int i=1;i<=p[x];i++)
				for(int j=1;j<=p[y];j++)
					chn(ans,w[x]+w[y]+dis[bel[x][i]][bel[y][j]]+t[x][i]+t[y][j]);
			printf("%lld\n",ans);
		}
		return 0;
	}
}
char END;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifdef XYHQ
	printf("Memory : %lld MB\n",(&BEGIN-&END)>>20);
	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
#else
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
//	clock_t begin=clock();
	hwq::main();
//	clock_t end=clock();
//	cerr<<"Time : "<<((double)end-(double)begin)/1000.0<<" s"<<endl;
	return 0;
}
