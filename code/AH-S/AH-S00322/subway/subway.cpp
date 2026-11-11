#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<"\n";
using namespace std;
const int MOD=1e9+7;
ll INF=1e18;
const int N=500005;
int c,n,m,d,q;
int w[N];
vector<pii> vec[N];
int dis[505][505];
void solve_(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			vec[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				int x=vec[i][j].fi,y=vec[i][k].fi;
				dis[x][y]=min(dis[x][y],vec[i][j].se+vec[i][k].se);
				dis[y][x]=min(dis[x][y],dis[y][x]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		int ans=INF;
		for(auto [p1,t1]:vec[s]){
			for(auto [p2,t2]:vec[t]){
				ans=min(ans,dis[p1][p2]+t1+t2);
			}
		}
		cout<<ans+w[s]+w[t]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int multitest=0,testcase=1;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
