#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
inline void read(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9') ch=getchar();while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();}
int c,n,m,d,q,k[N],w[M],vis[N],x,y,Y[N],T[N];
ll dis[N][N];
vector<int> v[M],t[M];
inline void chmin(ll &x,ll y){x= x<y?x:y;}
inline void getdis(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chmin(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int j=1,a,tt;j<=k[i];j++){
			read(a),read(tt);
			v[a].push_back(i);
			t[a].push_back(tt);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int lv=v[i].size();
		for(int x=0;x<lv;x++)
			for(int y=0;y<lv;y++)
				chmin(dis[ v[i][x] ][ v[i][y] ],t[i][x]+t[i][y]);
	}getdis();
	while(q--){
		read(x),read(y);
		int lx=v[x].size(),ly=v[y].size();
		for(int i=0;i<ly;i++) Y[i]=v[y][i],T[i]=t[y][i];
		ll ans=1e18;
		for(int i=0;i<lx;i++){
			int vxi=v[x][i],txi=t[x][i];
			for(int j=0;j<ly;j++)
				chmin(ans,dis[vxi][Y[j]]+txi+T[j]);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
