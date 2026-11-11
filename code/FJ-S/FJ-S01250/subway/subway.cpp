#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int c,n,m,d,q,x,y,k;
long long w[N];
long long l[20005][505],ans;
bool vis[20005][505];
struct node{
	int line;
	int xx;
	long long t;
};
long long bfs(int u,int v){
	queue<node> q;
	q.push({0,u,0});
	long long mint=1e18;
	while(!q.empty()){
		node val=q.front();
		if(val.xx==v){
			
			mint=min(mint,val.t);
		}
		for(int i=1;i<=m;i++){
			if(l[i][val.xx]!=0&&!vis[i][val.xx]){
				vis[i][val.xx]=1;
				q.push({i,val.xx,val.t+l[i][val.xx]+l[val.line][val.xx]});
			}
		}
		for(int i=1;i<=n;i++){
			if(l[val.line][i]!=0&&!vis[val.line][i]){
				vis[val.line][i]=1;
				q.push({val.line,i,val.t});
			}
		}
		q.pop();
	}
	return mint;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa;
			long long tt;
			cin>>aa>>tt;
			l[i][aa]=tt;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				vis[i][j]=0;
			}
		}
		ans=w[x]+w[y];
		vis[x][y]=1;
		ans+=bfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
