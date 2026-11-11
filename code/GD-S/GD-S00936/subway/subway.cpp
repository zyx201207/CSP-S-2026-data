#include <bits/stdc++.h>
using namespace std;
struct node{int id,cnt;};
vector<int> g[510];
vector<int> way[500010];
vector<int> w(500010);
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int k[500010];
	int ch[5010][5010];
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int u,num;
			cin >> u >> num;
			ch[i][u]=num;
			g[i].push_back(u);
			way[u].push_back(i);
		}
	}
	while(q--){
		queue<node> q;
		int st,ed;
		cin >> st >> ed;
		int vis[500010];
		for(int i=0;i<=500005;i++)vis[i]=0;
		int ans=INT_MAX;
		for(int i=0;i<way[st].size();i++)q.push({way[st][i],w[st]+w[ed]});
		while(!q.empty()){
			int id=q.front().id,cnt=q.front().cnt;
			q.pop();
			bool flg=0;
			for(auto i:g[id]){
				if(i==ed){
					ans=min(ans,cnt);
					flg=1;
					break;
				}
			}
			for(auto i:g[id]){
				if(vis[i])continue;
				vis[i]=1;
				for(auto j:way[i]){
					if(j==id)continue;
					int cnt1=cnt+ch[id][i]+ch[j][i];
					q.push({j,cnt1});
				}
			}
		}
		cout << ans << "\n"; 
	}
    return 0;
}
