#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=507, M=5e5+7, D=27;
int C, n, m, d, q;
ll w[M];
int tp[M][D], cnt[M];ll cst[M][D];
ll lj[N][N];
int read(){
	int s=0;
	char c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9'){
		s=(s<<3)+(s<<1)+(c-'0');
		c=getchar_unlocked();
	}
	return s;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	C=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k=read(), x;ll y;
		while(k--){
			x=read();y=read();
			int tot=(++cnt[x]);
			tp[x][tot]=i;
			cst[x][tot]=y;
		}
	}
	memset(lj, 0x3f, sizeof(lj));
	for(int i=1;i<=n;i++) lj[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=2;j<=cnt[i];j++){
			for(int k=1;k<j;k++){
				int u=tp[i][j], v=tp[i][k];
				lj[u][v]=lj[v][u]=min(lj[u][v], cst[i][j]+cst[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				lj[i][j]=min(lj[i][j], lj[i][k]+lj[k][j]);
	while(q--){
		int u=read(), v=read();
		ll ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				ans=min(ans, cst[u][i]+cst[v][j]+lj[tp[u][i]][tp[v][j]]);
			}
		}
		printf("%lld\n", ans+w[u]+w[v]);
	}
	return 0;
}