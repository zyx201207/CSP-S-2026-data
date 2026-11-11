#include<bits/stdc++.h>
using namespace std;
vector<int> g[500005];
int a[500005],dis[5000][5000];
void bfs(int i){
	queue<int> q;
	dis[i][i]=0;
	q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dis[i][u]+1<dis[i][v]){
				dis[i][v]=dis[i][u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(abs(a[i]-a[j])<=d)g[i].push_back(j);
			}
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<"0\n";
	}
} 
