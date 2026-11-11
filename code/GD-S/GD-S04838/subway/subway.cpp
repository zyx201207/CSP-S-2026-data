#include<bits/stdc++.h> 
using namespace std;
long long c,n,m,d,q,b[5000007],T,a[200+7][500007],k[300],vis[1000000];
long long x,y;
map<long long,vector<long long>>mp;
struct N{
	long long x,sum;
};
void bfs(){
	queue<N>q;
	q.push({x,0});
	while(!q.empty()){
		N u=q.front();
		q.pop();
		if(u.x ==y){
			cout<<b[x]+b[y]+u.sum *T<<"\n";
			return ;
		}
		for(auto v:mp[u.x ]){
			for(long long j=1;j<=k[v];j++){
				if(a[v][j]==u.x ||vis[a[v][j]])continue;
				vis[a[v][j]]=1;
				q.push({a[v][j],u.sum +1ll});
			}
		}
	} 
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>b[i];
	}for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>T;
			mp[a[i][j]].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		memset(vis, 0, sizeof vis);
		bfs();
	}
	return 0;
}
