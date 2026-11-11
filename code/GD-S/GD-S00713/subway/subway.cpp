#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
const int N=510,M=5e5+10;
int n,m,d,q,w[M];
ll dp[N][N];
vector<pair<int,ll>>a[M];
vector<pair<int,ll>>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios;
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,T;
			cin>>x>>T;
			a[x].push_back({i,T});
			e[i].push_back({x,T});
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++){
		for(auto u:e[i]){
			int x=u.first;
			ll w2=u.second;
			for(auto v:a[x]){
				int to=v.first;
				ll w=v.second;
				if(to==i)continue;
				dp[i][to]=min(dp[i][to],w+w2);
				dp[to][i]=dp[i][to];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dp[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				if(dp[k][j]==inf)continue;
				if(i==j)continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		ll ans=inf;
		for(auto u:a[x]){
			int to=u.first;
			for(auto v:a[y]){
				int to2=v.first;
				if(to==to2){
					ans=min(ans,u.second+v.second);
				}else{
					if(dp[to][to2]==inf)continue;
					ans=min(ans,dp[to][to2]+u.second+v.second);
				}
			}
		}
		cout<<(ans+w[x]+w[y])<<'\n';
	}
	return 0;
}

