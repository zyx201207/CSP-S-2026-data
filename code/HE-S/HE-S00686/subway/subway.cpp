#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+510;
struct node{
	int u,w;
};
int c,n,m,d,q1;
int a[N],l;
int dis[N],flag[N];
vector<node> e[N];
queue<int> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	l = m;
	for(int i = 1;i<=n;i++){
		int tot;
		cin>>tot;
		l++;
		for(int j = 1;j<=tot;j++){
			int v,w;
			cin>>v>>w;
			e[l].push_back({v,w});
			e[v].push_back({l,w});
		}
	}
	while(q1--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(flag,0,sizeof(flag));
		while(q.empty()!=1){
			q.pop();
		}
		q.push(x);
		flag[x] = 1;
		dis[x] = 0;
		while(q.empty()!=1){
			int x = q.front();
			q.pop();
			for(int i = 0;i<e[x].size();i++){
				int u = e[x][i].u;
				int w = e[x][i].w;
				if(flag[u]==1){
					continue;
				}
				if(dis[u]>dis[x]+w){
					dis[u] = dis[x]+w;
					q.push(u);
				}
			}
		}	
		cout<<dis[y]+a[x]+a[y]<<endl;
	}
	return 0;
}
