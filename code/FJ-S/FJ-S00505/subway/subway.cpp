#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5; 
const int INF=1e15;
int c,n,m,d,p,qw;
long long w[N];
struct P{
	int v;
	long long t;
};
bool inq[N+M+5];
long long dis[N];
vector<P> g[N];
void spfa(int x){
	//cout<<1<<" ";
	queue<int> q;
	for(int i=0;i<=m+n+1;i++)
	dis[i]=INF;
	dis[x]=0;
	inq[x]=1;
	q.push(x);
//	cout<<2<<" ";
	while(!q.empty()){
	///	cout<<3<<" ";
		int u=q.front();
		inq[u]=0;
		q.pop();
		for(auto y:g[u]){
			if(dis[u]+y.t<dis[y.v]){
				dis[y.v]=dis[u]+y.t;
				if(!inq[y.v]){
					q.push(y.v);
					inq[y.v]=1;
				}
			}
		}
	}
}
struct as{
	int v,id;
};
vector<as> que[M];
bool is[N+5];
vector<int> que2;
long long ans[M];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>qw;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){ //输入线路i经过的站 
int k;
	cin>>k;
	int v=i+m;
	for(int j=1;j<=k;j++){
		int u;
		long long t;
		cin>>u>>t;
		g[u].push_back({v,t});
		g[v].push_back({u,t});
	}
}

for(int i=0;i<qw;i++){
	int u,v;
	cin>>u>>v;
	que[u].push_back({v,i});
	if(!is[u]){
		que2.push_back(u);
		is[u]=1;
	}
}
for(long long x:que2){
spfa(x);
for(auto pos:que[x]){
	long long y=pos.v;
	long long id=pos.id;
	ans[id]=dis[y]+w[x]+w[y];
}
}
for(int i=0;i<qw;i++){
	cout<<ans[i]<<"\n";
}
return 0;
}

