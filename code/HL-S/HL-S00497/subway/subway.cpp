#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> t[505];
int c,n,m,d,q,w[500005],tot;
int bfs(int u,int v){
	int ans=INT_MAX;
	vector<bool> vis(m+5);
	queue<pair<int,int> > q;
	q.push({u,0});
	vis[u]=1;
	while(!q.empty()){
		auto p=q.front();q.pop();
//		cout<<p.first<<' '<<p.second<<endl;
		if(p.first==v){
			ans=min(ans,p.second);
			continue;
		}
		for(auto to:t[p.first]){
			if(!vis[to.first]){
//				cout<<"    "<<to.first;
				vis[to.first]=1;
				if(to.first==v){
					q.push({to.first,p.second+to.second});
				}else{
					q.push({to.first,p.second+to.second+t[to.first][to.first]});
				}
			}
		}
//		cout<<endl;
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,id,ti,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>id>>ti;
			t[i][id]=ti;
//			t[id][i]=ti;
		}
	}
	while(q--){
		tot=INT_MAX;
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+t[u][u]+bfs(u,v)<<'\n';
	}
	return 0;
}