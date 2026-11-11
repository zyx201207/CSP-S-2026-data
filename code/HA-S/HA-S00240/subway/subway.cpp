#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e2+10,M=5e5+10;
int c,n,m,d,p,sum;
int kou[M],ww[M],dist[M],self[M];
struct node{
	int v,w;
};
vector<node>g[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;++i){
		cin>>ww[i];
	}
	int k,v,w;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>v>>w;
			if(v!=i){
				g[i].push_back({v,w});
				g[v].push_back({i,w});
			}
			else{
				self[i]=w;
			}
		}
	}
	int x,y;
	while(p--){
		cin>>x>>y;
		sum=ww[x]+ww[y];
		queue<int>q;
		q.push(x);
		memset(dist,0,sizeof(dist));
		while(!q.empty()){
			int u=q.front();
			for(int i=0;i<g[u].size();++i){
				v=g[u][i].v,w=g[u][i].w;
				if(!dist[v]){
					dist[v]=self[u]+dist[u]+w;
					q.push(v);
				}
				if(dist[v]>self[u]+dist[u]+w){
					dist[v]=self[u]+dist[u]+w;
				}
			}
			q.pop();
		}
		cout<<sum+dist[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 4 6 20 1
1 1 1 1 1 1
3 1 4 2 3 3 5
2 2 3 4 8
2 3 3 4 3
3 6 4 4 2 5 9
1 5
*/
