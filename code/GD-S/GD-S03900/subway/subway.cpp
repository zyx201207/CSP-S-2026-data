#include<bits/stdc++.h>
using namespace std;
int w[500050],a,t;
int c,n,m,d,q;
struct node{
	int u,v;
};
vector<node>e[500050]; 
int dj(int s,int k){
	int dist[500050];
	for(int i=1;i<=m;i++){
		dist[i]=INT_MAX;
	}
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({s,0});//节点 路程  
	while(!q.empty()){
		int x=q.top().first,dis=q.top().second;
		q.pop();
		if(dis>dist[x])continue;
		for(auto p:e[x]){ 
			int a=p.u,b=p.v;//
			if(dist[a]>dist[x]+b+w[x]){
				dist[a]=dist[x]+b+w[x];
				q.push({a,dist[a]});
			}
		}
	}
	return dist[k];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		for(int j=1;j<=z;j++){
			cin>>a>>t;
			e[i].push_back({a,t});
		}
		
	}
	for(int i=1;i<=q;i++){
		int s,k;
		cin>>s>>k;		
		cout<<dj(s,k)<<endl;
	}
}
