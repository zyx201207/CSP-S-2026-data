#include<bits/stdc++.h>
#define long long ll
int c,n,m,d,q;
const int N=1000;
const int M=5e5+10;
int Q;
using namespace std;
struct Node{
	int to,sum;
};
int vis[N],dian[N],dis[N],lukou[N];
vector<Node> g[M];
void di(int qi){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,qi});
	vis[qi]=1;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto &edge:g[u]){
			int v=edge.to;
			int juli=edge.sum;
			if(vis[v]){
				if(dis[v]>dis[u]+juli){
					vis[v]=1;
					dis[v]=dis[u]+juli;
					q.push({dis[v],v});
				}			
			}
		}
		
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	int i;
	for(i=1;i<=m;i++){
		cin>>lukou[i];
	}
	while(n--){
		int k;
		cin>>k;
		for(i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			if(dian[x]!=0){
				g[i-1].push_back({i,dian[x]+y});
				g[i].push_back({i-1,dian[x]+y});
			}
			dian[x]=y;
		}
		while(Q--){
			int qi,z;
			cin>>qi>>z;
			di(qi);
			cout<<dis[z]+lukou[qi]+lukou[z]<<endl;
		}
	}
	return 0;
}

