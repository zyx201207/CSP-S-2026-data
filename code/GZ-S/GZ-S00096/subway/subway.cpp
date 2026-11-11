//GZ-S00096 ³Â¿¡Ñö 
#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;

int c,n,m,d,r;
int W[M];
struct chain{
	long long v,w;
	bool operator < (chain a)const{
		return a.w<w;
	}
};
vector<chain>a[N];
vector<chain>e[M];
long long dis[M];
void dijkstra(int s,int end){
	priority_queue <chain>q;
	for(int i=1;i<=m;i++){
		dis[i]=LONG_MAX;
	}
	dis[s]=0;
	q.push((chain){s,0});
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		int v=now.v;
		long long w=now.w;
		if(w>dis[v])continue;
		for(auto i:e[v]){
			if(i.w+w<dis[i.v]){
				dis[i.v]=i.w+w;
				q.push((chain){i.v,dis[i.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			a[i].push_back((chain){v,w});
		}
		for(auto j:a[i]){
			for(auto t:a[i]){
				if(j.v!=t.v)e[j.v].push_back((chain){t.v,j.w+t.w});
			}
		}
	}
	while(r--){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dis[y]+W[x]+W[y]<<"\n";
	}
	return 0;
}
