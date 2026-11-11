#include<bits/stdc++.h>
using namespace std;
long long dis[901010];
struct node{
	int v;
	int w;
	inline bool operator<(const node &x)const{
		return x.w<w;
	}
};
vector<node> e[901010];
bool vis[901010];
void dijkstra(int s){
	priority_queue<node> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(node{s,0});
	dis[s]=0;
	while(!q.empty()){
		node u=q.top();
		q.pop();
		vis[u.v]=1;
		for(int i=0;i<e[u.v].size();i++){
			int v=e[u.v][i].v;
			int w=e[u.v][i].w;
			if(dis[v]>dis[u.v]+w){
				dis[v]=dis[u.v]+w;
			}
			if(!vis[v]){
				q.push(node{v,dis[v]});
			}
		} 
	}
}
int a[501010];
int t[501010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int cnt=m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		e[i].push_back(node{m+i,x});
		e[m+i].push_back(node{i,x});
	}
	cnt=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			++cnt;
			e[cnt].push_back(node{m+a[j],t[j]});
			e[m+a[j]].push_back(node{cnt,t[j]});
			if(j==1){
				continue;
			}
			else{
				e[cnt].push_back(node{cnt-1,0});
				e[cnt-1].push_back(node{cnt,0});
			}
		}
	}
	/*for(int i=1;i<=cnt;i++){
		cout<<i<<" ";
		for(int j=0;j<e[i].size();j++){
			cout<<e[i][j].v<<" "<<e[i][j].w<<" ";
		}
		cout<<endl;
	}*/
	
	while(p--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<endl;
	}
	return 0;
}
