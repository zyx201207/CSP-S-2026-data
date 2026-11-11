#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=510,M=5e5+10,inf=1e18;
int n,m,d,q,a[M];
vector<pii >ve[N],te[M];
int f[N][N];
#undef int 
int main(){
#define int long long 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;
	scanf("%lld%lld%lld%lld%lld",&T,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%lld",&k);
		while(k--){
			int x,y;scanf("%lld%lld",&x,&y);
			te[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i!=j)f[i][j]=inf;
	}
	for(int i=1;i<=m;i++){
		for(pii p:te[i])for(pii q:te[i])if(p.fi!=q.fi){
			f[p.fi][q.fi]=f[q.fi][p.fi]=min(f[p.fi][q.fi],p.se+q.se);
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
		int x,y;scanf("%lld%lld",&x,&y);
		int ans=inf;
		for(pii p:te[x])for(pii q:te[y])
			ans=min(ans,p.se+q.se+f[p.fi][q.fi]);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}