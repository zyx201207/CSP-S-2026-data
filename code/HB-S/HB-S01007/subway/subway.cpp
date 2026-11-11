#include<bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7,Q=1e5+7;
int c,n,m,d,q,ans;
int w[M],dis[M+500],book[M+500];
vector<int> a[N],t[N];
vector<pair<int,int> > e[M+500];
void dijkstra(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,x});
	memset(dis,0x3f,sizeof dis);
	memset(book,0,sizeof book);
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(book[u]){
			continue;
		}
		book[u]=1;
		for(auto p:e[u]){
			int w=p.second,v=p.first;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ax,tx;
			cin>>ax>>tx;
			a[i].push_back(ax);
			t[i].push_back(tx);
			e[ax].push_back({M+i,tx});
			e[M+i].push_back({ax,tx});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
