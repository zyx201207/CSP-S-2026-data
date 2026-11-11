#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,p;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int w[100005];//依次表示从每个地铁站的地铁口走到站厅需要的时间。
struct node {
	int a,t;
};
vector<node>g1[505];//地铁站
vector<node>g2[100005];//地铁线
node plan[100005];
int vd1[505];
int vd2[100005];
struct node1{
	int f,a;
};
void bfs(int mark){
	queue<node1>q;
	q.push({1,plan[mark].a});
	vd1[plan[mark].a]=0;
	while(!q.empty()){
		node1 u=q.front();
		q.pop();
		if(u.f==1){
			for(int i=0;i<g1[u.a].size();i++){
				node v=g1[u.a][i];
				if(vd2[v.a]>vd1[u.a]+v.t){
					vd2[v.a]=vd1[u.a]+v.t;
					q.push({2,v.a});
				}
			}
		}
		if(u.f==2){
			for(int i=0;i<g2[u.a].size();i++){
				node v=g2[u.a][i];
				if(vd1[v.a]>vd2[u.a]+v.t){
					vd1[v.a]=vd2[u.a]+v.t;
					q.push({1,v.a});
				}
			}
		}
	}
	cout<<vd1[plan[mark].t]<<endl;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			g2[i].push_back({x,y});
			g1[x].push_back({i,y});
		}
	}
	for(int i=0;i<p;i++){
		cin>>plan[i].a>>plan[i].t;
		for(int j=1;j<=m;j++)vd1[j]=INT_MAX;
		for(int j=1;j<=n;j++)vd2[j]=INT_MAX;
		bfs(i);
	}
	return 0;
} 
