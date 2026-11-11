#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+5;
using ll = long long;
int c,n,m,d,q;
int w[N];
int k[N];
ll dis[N];
bool vis[N] = {false};
bool visn[N][N] = {false};
vector<int> a[N];
vector<int> t[N];
vector<int> node[N];
map<int,vector<int>> dian;
vector<pair<int,ll>> g[N];
struct Compare{
	bool operator()(pair<int,ll>& a,pair<int,ll>& b){
		return a.second>b.second;
	}
};
priority_queue<pair<int,ll> ,vector<pair<int,ll>> , Compare> pq;
ll dij(int x,int y){
	dis[x] = 0;
	pq.push({x,0});
	while(pq.size()){
		auto hd = pq.top();
		pq.pop();
		if(hd.first == y) return dis[y];
		if(vis[hd.first] == 1) continue;
		
		vis[hd.first] = true;
		for(auto i:g[hd.first]){
			int v = i.first;
			int w = i.second;
			if(dis[v] > hd.second+w){
				dis[v] = hd.second+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
vector<int> chg;
int x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int na,nt;
			cin>>na>>nt;
			a[i].push_back(na);
			t[i].push_back(nt);
			dian[na].push_back(i);
			if(dian[na].size() >= 1) chg.push_back(na);
		}
	}
	for(auto i:chg){
		for(int num = 0;num<dian[i].size();num++){
			for(int num2 = num+1;num2<dian[i].size();num2++){
				int j = dian[i][num];
				int k = dian[i][num2];
				if(j == k || visn[j][k] == true || visn[k][j] == true) continue;
//				cout<<i<<" "<<j<<" "<<k<<" "<<t[j][i]+t[k][i]<<endl;
				visn[j][k] = true;
				visn[k][j] = true;
				g[k].push_back({j,a[j][i]+a[k][i]});
				g[j].push_back({k,a[j][i]+a[k][i]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll ans = INT_MAX;
		int x,y;
		cin>>x>>y;
		int bas = w[x] + w[y];
		for(auto nx:dian[x]){
			for(auto ny:dian[y]){
				if(nx == ny) continue;
				cout<<nx<<" "<<ny<<endl;
				cout<<dij(nx,ny);
//				ans = min(ans,dij(nx,ny) + bas);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
