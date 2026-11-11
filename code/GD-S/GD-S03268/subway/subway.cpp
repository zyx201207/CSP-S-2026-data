#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int c,n,m,d,q;
long long w[N],k[505],dp[505][505],g[505][505];

struct node{
	int K,t;
};

vector<node> f[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j) continue;
			g[i][j] = 1e18;
			dp[i][j] = 1e18;
		}
	}
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	int a,t;
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a,&t);
			for(node e : f[a]){
//				cout << e.K << " " << i << " " << t+e.t;//
				g[i][e.K] = min(g[i][e.K],1ll*t+1ll*e.t);
				g[e.K][i] = min(g[e.K][i],1ll*t+1ll*e.t);
			}
//			cout << endl;//
			f[a].push_back({i,t});
		}
	}
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(min(g[i][j],dp[i][j]),dp[i][h]+dp[h][j]);
//				printf("i %d j %d dp %lld\n",i,j,dp[i][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		long long ans = 1e18;
		for(node xx : f[x]){
			for(node yy : f[y]){
				ans = min(ans,1ll*xx.t+1ll*yy.t+w[x]+w[y]+dp[xx.K][yy.K]);
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
