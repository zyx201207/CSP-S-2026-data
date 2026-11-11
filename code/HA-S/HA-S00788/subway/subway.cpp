#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,w[500001],k[500001],x,y,ans;
vector<int> a[501],t[501],g[501];
queue<pair<int,int> >q;
void bfs(int x,int y){
	ans=INT_MAX;
	q.push({x,0});
	while(!q.empty()){
		int u=q.front().first,v=q.front().second;
		q.pop();
		if(u==y){
			ans=min(ans,v);
		}
		if(v>ans) continue;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				if(u==a[i][j]&&j!=a[i].size()-1){
					q.push({a[i][j+1],v+t[i][j]});
				}
			}
		}
	}
	cout<<ans+w[x]+w[y]<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
		}
	}
	for(int i=1;i<=qq;i++){
		cin>>x>>y;
		bfs(x,y);
	} 
}
