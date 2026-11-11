#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int M=5e5;
vector<pair<int,long long>> g[2*M+N+1];// Õ¾Ì¨:1-5e5£»Õ¾Ìü:5e5+1-1e6£»ÏßÂ·:1e6+1-1e6+500
int dis[2*M+N+1];
void dijsktra(int start,int end){
	vector<bool> vis(2*M+N+1);
	vis[start]=true;
	dis[start]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> priQue;
	priQue.push(make_pair(0ll,start));
	while(!priQue.empty()){
		int u=priQue.top().second;
		priQue.pop();
		for(auto a:g[u]){
			int v=a.first;
			int x=a.second;
			if(vis[v]) continue;
			vis[v]=true;
			dis[v]=dis[u]+x;
			if(v==end) return ;
			priQue.push(make_pair(dis[u]+x,v));
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].emplace_back(M+i,w);
		g[M+i].emplace_back(i,w);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[M+a].emplace_back(2*M+i,t);
			g[2*M+i].emplace_back(M+a,t);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijsktra(x,y);
		cout<<dis[y]<<endl;
//		cerr<<dis[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
