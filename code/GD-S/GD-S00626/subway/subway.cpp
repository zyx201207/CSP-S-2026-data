#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
#define fi first
#define se second
#define chkmin(x,y) (x=min(x,y))
#define chkmax(x,y) (x=max(x,y))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
const int N=5e2+5;
const int M=5e5+5;
const ll inf=1e18;
int n,m,d,q,w[M],k,a,t,x,y;
ll dis[N][N];
vector<PII> route[M]; 
void solve(){
	read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;++i) read(w[i]);
	int s=0;	
	for(int i=1;i<=n;++i){
		read(k);
		for(int j=1;j<=k;++j){
			read(a),read(t);
			route[a].emplace_back(PII(i,t));
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=inf;
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int p=route[i].size();
		for(int j=0;j<p;++j)
			for(int k=j+1;k<p;++k){
				int u=route[i][j].fi,v=route[i][k].fi;
				chkmin(dis[u][v],0ll+route[i][j].se+route[i][k].se);
				chkmin(dis[v][u],0ll+route[i][j].se+route[i][k].se);
			}
	}
	for(int k=1;k<=n;++k)	
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		read(x),read(y);
		int p=route[x].size(),q=route[y].size();
		ll ans=inf;
		for(int i=0;i<p;++i)
			for(int j=0;j<q;++j)
				chkmin(ans,route[x][i].se+route[y][j].se+dis[route[x][i].fi][route[y][j].fi]);
		ans+=0ll+w[x]+w[y];
		write(ans);
		putchar('\n');
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=1,T=1;
	read(c);
	while(T--) solve();
	return 0;
} 
