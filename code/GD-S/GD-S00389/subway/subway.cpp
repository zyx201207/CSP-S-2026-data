#include <bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int M=1e6+10;
const long long inf=(1ll<<50);
int c,n,m,d,q,w[M];
long long f[N][N];
struct st{
	int i,t;
};
vector<st> z[M];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)f[i][j]=0;else f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			z[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto &x:z[i]){
			for(auto &y:z[i]){
				if(x.i==y.i)continue;
				f[x.i][y.i]=min(f[x.i][y.i],(long long)(x.t+y.t));
				f[y.i][x.i]=min(f[y.i][x.i],(long long)(x.t+y.t));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=inf;
		for(auto &a:z[x]){
			for(auto &b:z[y]){
				ans=min(ans,f[a.i][b.i]+w[x]+w[y]+a.t+b.t);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
