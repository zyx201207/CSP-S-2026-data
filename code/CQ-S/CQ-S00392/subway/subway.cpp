#include<bits/stdc++.h>
using namespace std;
#define int long long
const int R=1e12;
int n,m,q;
int a[50005],vis[51000];
vector<int>e[51000],h[51000];
vector<int>d[51000];
void js(int f){
	if(d[f].size()!=0)return;
	for(int i=0;i<=n+m+5;i++)d[f].push_back(R),vis[i]=0;
	priority_queue<array<int,2>>q;
	q.push({0,f});
	d[f][f]=0;
	while(q.size()){
		int u=q.top()[1];
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i],w=h[u][i];
			if(d[f][v]>d[f][u]+w){
				d[f][v]=d[f][u]+w;
				q.push({-d[f][v],v});
			}
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			e[i+m].push_back(y);
			e[y].push_back(i+m);
			h[i+m].push_back(z);
			h[y].push_back(z);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		js(x);
		cout<<a[x]+a[y]+d[x][y]<<endl;
	}
	return 0;
}
