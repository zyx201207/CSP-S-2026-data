#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int c,n,m,d,q;
int tun[N];
struct Edge{
	int to,id;
};
vector<Edge> G[N];
int to_plat[503][1003];
struct node{
	int x,cost,use_id;
	bool on_plat;
};
int dist[1003];
int solve(int l,int r){
	memset(dist,0x3f,sizeof dist);
//	priority_queue<node> pq;
	queue<node> pq;
	pq.push({l,0,0,1});
	dist[l]=0;
	while(!pq.empty()){
		node head=pq.front();
		pq.pop();
		if(head.on_plat){
			if(dist[head.x]<head.cost) continue;
			dist[head.x]=head.cost;
			if(head.x==r) break;
		}
		for(int i=0;i<(int)G[head.x].size();i++){
			int v=G[head.x][i].to;
			int w=head.cost;
			if(head.on_plat){
				pq.push({v,w+to_plat[G[head.x][i].id][head.x],G[head.x][i].id,0});
				pq.push({v,w+to_plat[G[head.x][i].id][head.x],0,1});
			}
			else{
				pq.push({v,w,G[head.x][i].id,0});
				pq.push({v,w+to_plat[head.use_id][head.x],0,1});
			}
		}
	}
	return dist[r]+tun[r]+tun[l];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>m>>n>>d>>q;	
	for(int i=1;i<=n;i++) cin>>tun[i];
	for(int i=1,k,last=0;i<=m;i++){
		cin>>k;
		for(int j=1,tmp;j<=k;j++){
			cin>>tmp;
			if(last!=0){
				G[last].push_back({tmp,i});
				G[tmp].push_back({last,i});
			}
			cin>>to_plat[tmp][i];
			last=tmp;
		} 
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<solve(l,r)<<"\n";
	}
	return 0;
}
