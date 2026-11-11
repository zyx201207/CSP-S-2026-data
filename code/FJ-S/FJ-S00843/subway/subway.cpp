#include<bits/stdc++.h>
#define ll long long
#define PLL pair<ll,ll>
using namespace std;
const int N=500010,M=510;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
ll C,n,m,D,Q;
ll a[N];

ll f[M][M];
vector<PLL> v[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		ll X=read();
		for(int j=1;j<=X;j++){
			ll x=read(),y=read();
			v[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=INF;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				ll x=v[i][j].first,y=v[i][k].first;
				f[x][y]=f[y][x]=min(f[x][y],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--){
		ll x=read(),y=read();
		ll ans=INF;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				ans=min(ans,f[v[x][j].first][v[y][k].first]+v[x][j].second+v[y][k].second+a[x]+a[y]);
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
