#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e6+5,MAXM=500+5,inf=1e18;
struct edge{
	ll to,v;
};
int c,n,m,d,q;
vector<edge> v[MAXN];
ll f[MAXM][MAXM];
ll w[MAXN];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
}
void build(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	init();
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			ll y,z;
			scanf("%lld%lld",&y,&z);
			v[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				edge tmp1=v[i][j],tmp2=v[i][k];
				f[tmp1.to][tmp2.to]=min(f[tmp1.to][tmp2.to],tmp1.v+tmp2.v);
				f[tmp2.to][tmp1.to]=min(f[tmp2.to][tmp1.to],tmp1.v+tmp2.v);
			}
		}
	}
	build();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				edge tmp1=v[x][i],tmp2=v[y][j];
				ans=min(ans,w[x]+w[y]+tmp1.v+tmp2.v+f[tmp1.to][tmp2.to]);
			}
		}
		printf("%lld\n",ans);
	}
}
