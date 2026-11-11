#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=5e2+10,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,a[N],k,x,y,f[M][M],ans,b[N];
vector<ll> cnt[N],cntt[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			cnt[x].push_back(i);
			cntt[x].push_back(y);
			b[x]++;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i];j++){
			ll x=cnt[i][j],w1=cntt[i][j];
			for(int k=0;k<b[i];k++){
				ll y=cnt[i][k],w2=cntt[i][k];
				if(x==y){
					continue;
				}
				f[x][y]=f[y][x]=min(f[x][y],w1+w2);
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
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=INF;
		for(int i=0;i<b[x];i++){
			ll u=cnt[x][i],w1=cntt[x][i];
			for(int j=0;j<b[y];j++){
				ll v=cnt[y][j],w2=cntt[y][j];
				ans=min(ans,f[u][v]+w1+w2);
			}
		}
		ans+=a[x]+a[y];
		printf("%lld\n",ans);
	}
	return 0;
}
