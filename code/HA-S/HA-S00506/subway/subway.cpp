#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
long long dis[500005];
bool vis[500005];
struct node{
	long long v,w;
	bool operator <(const node & a)const{
		return w>a.w;
	}
};
vector<node> ve[500005];
void dj(int s){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		long long x=q.top().v;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto y : ve[x]){
			if(dis[y.v]>dis[x]+y.w){
				dis[y.v]=dis[x]+y.w;
				q.push({y.v,dis[y.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long cnt=m;
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long v,t;
			cin>>v;
			cnt++;
			if(j>1){
				ve[cnt].push_back({cnt-1,0});
				ve[cnt-1].push_back({cnt,0});
			}
			cin>>t;
			ve[v].push_back({cnt,t});
			ve[cnt].push_back({v,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
