#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1005;
int c,n,m,d,q,w[M],t[M],a[M],dis[M][M];
bool vis[M];
vector<pair<int,int> >e[M];
void bfs(int s){
	for(int i=1;i<=m;i++) vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que;
	dis[s][s]=0;
	que.push({0,s});
	while(!que.empty()){
		int u=que.top().second,st=que.top().first;
//		cout<<u<<' '<<st<<'\n';
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<int,int> i:e[u]){
//			cout<<i.first<<' '<<i.second<<'\n';
			if(dis[s][i.first]>st+(i.second)){
				dis[s][i.first]=st+i.second;
				que.push({dis[s][i.first],i.first});
//				cout<<i.first<<' '<<dis[s][i.first]<<'\n';
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				e[a[j]].push_back({a[l],t[j]+t[l]});
				e[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		bfs(i);
	}
	while(q--){
		int s,t;cin>>s>>t;
		cout<<dis[s][t]+w[s]+w[t]<<'\n';
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
