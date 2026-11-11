#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x;scanf("%lld",&x);return x;}
const int N=510;
const int inf=1e9+7;
int dis[N];
vector<pair<pair<int,int>,int > > g[N];
int w[N];
void dij(int s){
	fill(dis,dis+N,inf);
	dis[s]=0;
	priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,s});
	while(pq.size()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d>dis[u]) continue;
		for(auto w:g[u]){
//			cout<<w.first<<w.second<<endl;
			if(dis[w.second]>dis[u]+w.first.first){
				dis[w.second]=dis[u]+w.first.first;
				pq.push({dis[w.first.second],w.first.second});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		int a1=0;
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			if(j==1) a1=a;
			else{
				g[a1].push_back({{a,t},i});
				a1=a;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		dij(y);
		cout<<min(w[x]+w[y],dis[x]+w[x]+w[y])<<endl;
	}
	return 0;
}
