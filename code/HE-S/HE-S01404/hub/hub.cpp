#include<bits/stdc++.h>
using namespace std;
int Dist[101];
int c,t;vector<int> E[101];
int ans=1000000,tmp;
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	memset(Dist,0x3f,sizeof Dist);
	Dist[s]=0;
	pq.push({s,0});
	tmp=-1;
	while(!pq.empty()){
		pair<int,int> cur=pq.top();pq.pop();
		int u=cur.first;
		for(int v : E[u]){
			if(Dist[u]+1<Dist[v]){
				Dist[v]=Dist[u]+1;
				pq.push({v,Dist[v]});
				tmp=max(tmp,Dist[v]);
			}
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			E[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dij(i);
			ans=min(ans,tmp);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
