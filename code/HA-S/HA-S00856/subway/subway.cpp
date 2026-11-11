#include<bits/stdc++.h>//卡了兄弟，一个小时才把T1A掉 
using namespace std;
int n,m,c,d,q;
long long w[500005];
long long dis[500005];
int vis[500005];
struct station{
	int id;
	vector<int>t;
	vector<int>s;
}a[500001];
vector<int>v[501];
void bfs(int start,int tag){
	queue<int>q;
	vis[start]=tag;
	dis[start]=0;
	q.push(start);
	while(!q.empty()){
		int o=q.front();
		q.pop();
		for(int i=0;i<a[o].s.size();i++){
			for(int j=0;j<v[a[o].s[i]].size();j++){
				int to=v[a[o].s[i]][j];
				if(vis[to]!=tag){
					vis[to]=tag;
					dis[to]=dis[o]+2*a[o].t[i];
					q.push(to);
				}
			}
		}
	}
}
void dijkstra(int start,int tag){
	priority_queue< pair<int,int> >q;
	memset(dis,0x3f,sizeof(dis));
	vis[start]=tag;
	dis[start]=0;
	q.push(make_pair(0,start));
	while(!q.empty()){
		int o=q.top().second;
		int d=-q.top().first;
		q.pop();
		if(vis[o]==tag)continue;
		vis[o]=tag;
		for(int i=0;i<a[o].s.size();i++){
			for(int j=0;j<v[a[o].s[i]].size();j++){
				int to=v[a[o].s[i]][j];
				bool flag=0;
				for(int l=0;l<a[to].s.size();l++){
					if(a[to].t[l]==i){
						if(dis[to]>d+a[o].t[i]+a[to].t[l]){
							flag=1;
							dis[to]=d+a[o].t[i]+a[to].t[l];
						}
					}
				}
				if(flag){
					q.push(make_pair(-dis[to],to));
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int len,b,t;
		cin>>len;
		for(int j=1;j<=len;j++){
			scanf("%d%d",&b,&t);
			v[i].push_back(b);
			a[b].s.push_back(i);
			a[b].t.push_back(t);
		}
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			bfs(u,i);
			printf("%lld\n",dis[v]+w[u]+w[v]);
		}
	}else{
		for(int i=1;i<=q;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			dijkstra(u,i);
			printf("%lld\n",dis[v]+w[u]+w[v]);
		}	
	}
	return 0;
}
