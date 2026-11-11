#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
vector<pair<int,int> > v[N];
int c,n,m,d,q,k,a,b,mi; 
int w[N],vis[N]; 
void dfs(int u,int cnt){
	if(u == b){
		mi = min(mi,cnt);
		return ;
	}
	for(auto x : v[u]){
		if(vis[x.first]) continue;
		vis[x.first] = 1;
		cnt += x.second;
		dfs(x.first,cnt + w[x.first]);
		vis[x.first] = 0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d>>q;
	for(int i = 1;i<=m;i++) cin >> w[i];
	
	for(int i = 1;i<=n;i++){
		int t,a1;
		cin >> k;
		for(int j = 1;j<=k;j++) {
			cin >> a1>> t;  
			v[i].push_back({a1,t});
			v[a1].push_back({i,t});
		}
	} 
	while(q--){
		cin >> a >> b;
		mi = LLONG_MAX;
		memset(vis,0,sizeof vis);
		vis[a]=1;
		dfs(a,w[a]);
		cout << mi + w[b] << "\n";
	}
	return 0;
} 
