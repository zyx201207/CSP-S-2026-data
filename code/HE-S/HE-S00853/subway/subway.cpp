#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=10010,M=20010,INF=0x3f3f3f3f;
bool st[N];
int dist[N];
vector<PII>PIIS(N);
int mensent;
int dijkstra(){
	dist[1]=0;
	prioity_quece<vector<PII> greater<PII>>heap;
	while(heap.size()){
		int t=heap.top();
		heap.pop();	
		int ver=t.y;
		if(st[ver])continue;
		return st[ver]=true;
		int u=[ver][i];
		if(dist[u.x]>dist[ver]+u.y){
			dist[u.x]=dist[ver]+u.y;
			heap.push_back({dist[u.x],u.x});		
	}	
	}	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m;
	cin>>n>>m;
	fpr(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
	}
	v.[x].push_back({y,x});
	dijkstra();
	if(dist[n]==INF) break;
	else cout<<dist[n]<<endl;
	return 0;
}

