#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,d,T;
int w[507],a[500007];
map<pair<int,int>,int> t;
struct node{
	int x,id,sum;
};
struct test{
	int y,id;
};
vector<pii> g[507];
int vis[507];
int bfs(int st,int to){
	queue<node> q;
	memset(vis,0,sizeof vis);
	q.push({st,0,0});
	int ans=1e18;
	while(!q.empty()){
		int x=q.front().x,id=q.front().id,sum=q.front().sum;
		q.pop();
		if(x==to){
			ans=min(ans,sum+t[{id,to}]);
		}
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:g[x]){
			int y=i.first,nid=i.second,w=0;
			if(id!=nid)w=t[{id,x}]+t[{nid,x}];
//			cout<<x<<" "<<y<<" "<<id<<" "<<nid<<" "<<w<<" "<<sum<<"\n";
			if(!vis[y]){
				q.push({y,nid,sum+w});
			}
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[{i,a[j]}];
		}
		for(int j=1;j<k;j++){
			for(int o=j+1;o<=k;o++){
				g[a[j]].emplace_back(a[o],i);
				g[a[o]].emplace_back(a[j],i);
//				cout<<a[j]<<" "<<a[o]<<"\n";
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<t[i][j]<<" ";
//		cout<<"\n";
//	}
	while(T--){
		int st,to;
		cin>>st>>to;
		cout<<bfs(st,to)+w[st]+w[to]<<"\n";
	}
	return 0;
}
