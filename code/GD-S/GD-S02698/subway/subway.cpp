#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	node(){}
	node(int xx,int yy):v(xx),w(yy){};
};
vector<node>v[300010];
int w[300010],d[300010];
priority_queue<pair<int,int> >q;
bool vis[300010];
void Dijkstra(int beg,int en){
	memset(vis,0,sizeof(vis));
	memset(d,127,sizeof(d));
	while(!q.empty())q.pop();
	q.push(make_pair(0,beg));
	d[beg] = 0;
	while(!q.empty()){
		pair<int,int> u = q.top();
		q.pop();
		vis[u.second] = 1;
		for(auto it:v[u.second]){
			if(vis[it.v])continue;
			if(d[it.v]>d[u.second]+it.w){
				d[it.v] = d[u.second]+it.w;
				q.push(make_pair(-d[it.v],it.v));
			}
		}
	}
	cout<<d[en]+w[beg]+w[en]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int c,n,m,d2,q;
	cin>>c>>n>>m>>d2>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++){
		int n2;
		cin>>n2;
		int lx,ly;
		cin>>lx>>ly;
		v[lx].push_back(node(i*d2,ly));
		v[i*d2].push_back(node(lx,ly));
		for(int j = 1;j<n2;j++){
			int x,y;
			cin>>x>>y;
			v[i*d2+j].push_back(node(i*d2+j-1,0));
			v[i*d2+j-1].push_back(node(i*d2+j,0));
			v[x].push_back(node(i*d2+j,y));
			v[i*d2+j].push_back(node(x,y));
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		Dijkstra(x,y);
	}
	return 0;
}
