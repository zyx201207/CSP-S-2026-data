#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,z,ans,s[500010],dis[510][510];
vector<pair<int,int>>a[510],b[501000];
void djs(){
	priority_queue<pair<int,int>>p;
	p.push({0,x});
	dis[x][x]=0;
	while(!p.empty()){
		int u=p.top().second;
		p.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].first,w=a[u][i].second;
			if(dis[x][v]>dis[x][u]+w){
				dis[x][v]=dis[x][u]+w;
				p.push({-dis[x][v],v});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			b[i].push_back({y+n,z});
			b[y+n].push_back({i,z});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<b[i].size();j++){
			int v=b[i][j].first,w=b[i][j].second;
			for(int k=0;k<b[v].size();k++){
				int vv=b[v][k].first,ww=b[v][k].second;
				if(i==vv) continue;
				a[i].push_back({vv,w+ww});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(x=1;x<=n;x++) djs();
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<b[x+n].size();i++){
			for(int j=0;j<b[y+n].size();j++){
				ans=min(ans,b[x+n][i].second+dis[b[x+n][i].first][b[y+n][j].first]+b[y+n][j].second);
			}
		}
		cout<<s[x]+ans+s[y]<<"\n";
	}
	return 0;
}
//16:41  100
