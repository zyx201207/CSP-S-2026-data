#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
int s[505], a[100005],j[100005],mn=1e9;
bool vis[505];

struct station{
	int t[10005]; //t[i] 为走到第i条线的所需时间 
	vector<int> s[10005]; //每个station连接的一条边 
}g[505];

void dfs(int x, int y, int time){
	//cout<<x<<" "<<time<<endl;
	if (x==y){
		mn=min(mn,time);
		return ;
	}
	vis[x]=1;
	for (int i=1;i<=n;i++){
		int addtime1 = g[x].t[i];
		for(auto nx:g[x].s[i]){
			int addtime2=g[nx].t[i];
			if (!vis[nx]) dfs(nx,y,addtime1 + addtime2 + time);
		}
	}
	return ;
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++){
		int z;
		cin>>z;
		for (int j=1;j<=z;j++){
			int t;
			cin>>a[j]>>t;
			if (j>=2){
				for (int k=1;k<j;k++){
					g[a[j-k]].s[i].push_back(a[j]);
					g[a[j]].s[i].push_back(a[j-k]);
				}
			}
			g[a[j]].t[i]=t;
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		mn=1e9;
		for (int i=1;i<505;i++) vis[i]=0; 
		dfs(x, y, 0);
		cout<<mn+s[x]+s[y]<<endl;
	}
	return 0;
}
