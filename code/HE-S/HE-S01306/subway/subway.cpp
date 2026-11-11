#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+10;
int ans,c,m,n,d,query,w[N],a[505][N],vis[N],t[505][N],ccf[N];
vector<int> mp[N];
struct edge{
	int v,w,route;
};
vector<edge> e[N];
struct Q{
	int u,sum,prer,prep;
};
queue<Q> q;

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>query;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]].push_back(i);
		}
	}

	for(int i=1;i<=query;i++){
		int ans=1e18;
		int x,y;
		cin>>x>>y;
		for(auto r:mp[x]){
			ans=min(t[r][x]+t[r][y]+w[x]+w[y],ans);
		}
		cout<<ans<<endl;
	}
}
