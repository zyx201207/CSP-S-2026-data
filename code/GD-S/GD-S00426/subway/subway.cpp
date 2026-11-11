#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x){
	T w=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=5e2+10,M=5e5+10;
typedef pair<int,int> pii;
#define fi first
#define se second
const ll inf=1e18;
vector<pii>pt[M];
int n,m,d,q;
int k[N];
vector<int>t[N],a[N];
ll dis[N][N],w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cid;read(cid);
	read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;++i) read(w[i]);
	for(int i=1;i<=n;++i){
		read(k[i]);
		t[i].resize(k[i]+3);
		a[i].resize(k[i]+3);
		for(int j=1;j<=k[i];++j){
			read(a[i][j]),read(t[i][j]);
			pt[a[i][j]].emplace_back(i,t[i][j]);	
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dis[i][j]=(j==i ? 0 : inf);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++j){
			int u=a[i][j];
			for(pii p : pt[u]) dis[i][p.fi]=min(dis[i][p.fi],1ll*t[i][j]+p.se);
		}
	}
	for(int o=1;o<=n;++o){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][o]+dis[o][j]);
		}
	}
	while(q--){
		int x,y;
		read(x),read(y);
		ll ans=inf;
		for(pii p : pt[x]){
			for(pii s : pt[y]){
				ans=min(ans,dis[p.fi][s.fi]+p.se+s.se);
			}
		}
		write(ans+w[x]+w[y]),putchar('\n');
	}
	return 0;
}

