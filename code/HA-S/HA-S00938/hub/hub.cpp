#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int> g[20001];
int d[20001]={0},fa[20001]={0};
int bfs(int x,int y){
	queue<pair<int,int> > q;
	q.push({x,y});
	int cnt=0,s=k;
	while(s>0){
		pair<int,int> t=q.front();
		q.pop();
		int u=t.first,v=t.second;
		int tx=0,ty=0,sx=0,sy=0;
		for(int i=0;i<d[u];i++){
			if(fa[g[u][i]]!=0){
				sx++;
			}else{
				tx=max(tx,d[g[u][i]]);
				fa[g[u][i]]=tx;
			}
		}
		for(int i=0;i<d[v];i++){
			if(fa[g[v][i]]!=0){
				sy++;
			}else{
				ty=max(ty,d[g[v][i]]);
				fa[g[v][i]]=ty;
			}
		}
		if(tx==0&&ty==0){
			return INT_MAX;
		}
		s-=(d[v]+d[u]-sx-sy);
		q.push({tx,ty});
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=INT_MAX;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			d[v]++;
			d[u]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					memset(fa,0,sizeof(fa));
					ans=min(ans,bfs(i,j));
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
