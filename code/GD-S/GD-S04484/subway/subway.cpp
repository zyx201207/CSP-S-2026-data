#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=5e2+5,M=5e5+5,D=25;
int c,n,m,d,q;
int w[M];
int dis[N*2][N*2],vis[N*2][N*2];
struct nd{
	int y,t;
};
vector<nd> a[M],b[M];
void spfa(int s){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=0;i<=m;i++)dis[s][i]=1e9;
	q.push({dis[s][s]=w[s],s});
	while(!q.empty()){
//		cout<<t<<endl;
		int t=q.top().second;
//		cout<<t<<endl;
		q.pop();
		if(vis[s][t])continue;
//		cout<<t<<endl;
		vis[s][t]=1;
		for(nd i:a[t]){
			for(nd j:b[i.y]){
//				cout<<s<<" "<<j.y<<" "<<dis[s][j.y]<<" "<<dis[s][t]+j.t<<endl;
				if(dis[s][j.y]>dis[s][t]+j.t+i.t){
					dis[s][j.y]=dis[s][t]+j.t+i.t;
					q.push({dis[s][j.y],j.y});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int y,t;
			cin>>y>>t;
			a[y].push_back({i,t});
			b[i].push_back({y,t});
		}
	}
	for(int i=1;i<=m;i++){
		spfa(i);
//		cout<<endl;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[y]<<endl;
	}
}
