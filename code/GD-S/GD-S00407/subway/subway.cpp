#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int a[500005];
vector<pair<int,int>>v[505],pu[500005];
struct info{
	int now,val;
	friend bool operator < (info x,info y){
		return x.val>y.val;
	}
};
int vis[505],di[500005];
int ans(int x,int y,int i){
	priority_queue<info>qp;
	for(auto nx:pu[x]){
		qp.push({nx.first,nx.second});
	}
	int an=9e18;
	while(!qp.empty()){
		info now=qp.top();
		qp.pop();
		if(vis[now.now]==i)continue;
		vis[now.now]=i;
		di[now.now]=now.val;
		for(auto nx:v[now.now]){
			if(vis[nx.first]==i)continue;
			qp.push({nx.first,now.val+nx.second});
		}
	}
	for(auto nx:pu[y]){
		an=min(an,nx.second+di[nx.first]);
	}
	return an;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,y,z;j<=x;j++){
			cin>>y>>z;
			pu[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:pu[i]){
			for(auto y:pu[i]){
				if(x.first==y.first)continue;
				v[x.first].push_back({y.first,x.second+y.second});
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<a[x]+a[y]+ans(x,y,i)<<'\n';
	}
	return 0;
}
