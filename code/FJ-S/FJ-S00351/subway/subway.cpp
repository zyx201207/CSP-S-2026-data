#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int c,n,m,d,q,k[505];
vector<long long> w;
vector<int> a[505];
vector<long long> t[505];
void printA(){
	w.resize(m+1);
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
}
void solveA(){
	printA();
	long long f[1005][1005];
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			f[i][j]=inf;
		}
	}
	while(1){
		bool b=1;
		for(int i=1;i<=n;i++){
			if(k[i]==2){
				int x=a[i][0],y=a[i][1];
				long long txy=t[i][0]+t[i][1];
				if(f[x][y]>txy){
					f[x][y]=txy;
					b=0;
				}
			}
		}
		if(b){
			break;
		}
	}	
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+f[x][y] << endl;
	}
}
vector<int> g[500005];
vector<bool> vis;
void printB(){
	vis.resize(m+1);
	w.resize(m+1);
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=0;j<k[i];j++){
			cin >> a[i][j] >> t[i][j];
			if(j>0){
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
}
int bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,0});
	while(q.size()){
		auto z=q.front();
		q.pop();
		int u=z.first,c=z.second;
		if(u==y){
			return c;
		}
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v]==0){
				q.push({v,c+1});
			}
		}
	}
	return -1;
}
void solveB(){
	printB();
	long long T=t[1][0];
	while(q--){
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+bfs(x,y)*2*T << endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(7<=c && c<=11){
		solveA();
	}else if(12<=c && c<=19){
		solveB();
	}
	return 0;
}
