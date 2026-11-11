#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int w[500010],k[510],dis[510][510];
vector <int> a[510],t[510];
vector <pair <int,int>> con[500010],mp[510];
signed main() {
	FAST
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			con[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=0; j<con[i].size(); j++) {
			for(int k=j+1; k<con[i].size(); k++) {
				int val=con[i][j].second+con[i][k].second;
				mp[con[i][j].first].push_back({con[i][k].first,val});
				mp[con[i][k].first].push_back({con[i][j].first,val});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++) {
		dis[i][i]=0;
		priority_queue <pair <int,int>,vector <pair <int,int>>,greater <pair <int,int>>> q;
		q.push({0,i});
		while(!q.empty()) {
			auto now=q.top();
			q.pop();
			if(dis[i][now.second]!=now.first) {
				continue;
			}
			for(auto j:mp[now.second]) {
				if(dis[i][j.first]>now.first+j.second) {
					dis[i][j.first]=now.first+j.second;
					q.push({dis[i][j.first],j.first});
				}
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		int ans=1000000000000000000;
		for(auto i:con[x]) {
			for(auto j:con[y]) {
				ans=min(ans,dis[i.first][j.first]+i.second+j.second+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
