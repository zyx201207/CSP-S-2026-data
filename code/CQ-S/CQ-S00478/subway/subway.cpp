#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,qq;
int val[N],dis[N],vis[N];
struct node{
	int to,w;
};
vector<node> e[505];
void dij(int s,int y){
	for(int i=1;i<=m;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto i: e[u]){
			int v=i.to,w=i.w;
			w+=e[u][u].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		int k,l1,t1;
		cin>>k;
		cin>>l1>>t1;
		for(int j=1;j<k;j++){
			int aa,tt;
			cin>>aa>>tt;
			e[l1].push_back({aa,t1});
			e[aa].push_back({l1,t1});
			l1=aa;
			t1=tt;
		}
	}
	int ii=0;
	while(qq--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
		cout<<dis[y]+val[x]+val[y]<<"\n";
	}
	return 0;
}
//¿Ú¡·Ì¨£ºval Ì¨¡·Ìü:t i i 
/*0 2 5 20 2
4 1 9 2 5
3 
1 5
2 7
4 6
3
2 3
3 4
5 7
1 3
1 2*/
