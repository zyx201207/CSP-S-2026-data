#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PIL=pair<int,long long>;
using PLI=pair<long long,int>;
const int N=510,M=2e4+10,MM=5e5+10;
ll dis[N][N];
int c,n,m,d,q;
ll w[M];
int k[N];
vector<ll>t[N],a[N];
vector<PIL>G1[M],G2[MM];
vector<int>G[M];
ll T=-1;
int f=1;
int mx=0;
int fa[M];
ll dis1[N][M],dis2[5][MM];
int vis[M];
int mxk;
void bfs(int s){
	queue<int>que;
	memset(vis,0,sizeof(vis));
//	cout<<s<<'\n';
	dis1[s-m][s]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		if(vis[u])continue;
//		cout<<u<<'\n';
		vis[u]=1;
		for(auto v:G[u]){
//			if(vis[v])continue;
			dis1[s-m][v]=dis1[s-m][u]+1;
			que.push(v); 
		}
	}
}
void dijk(int s){
	priority_queue<PLI,vector<PLI>,greater<PLI>>q;
	dis1[s-m][s]=0;
	q.push({0,s});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(PIL it:G1[u]){
			int v=it.first;
			ll w=it.second;
			dis1[s-m][v]=min(dis1[s-m][v],dis1[s-m][u]+w);
			q.push({dis1[s-m][v],v});
		}
	}
}
void dijk1(int s){
	priority_queue<PLI,vector<PLI>,greater<PLI>>q;
	dis2[s-m][s]=0;
	q.push({0,s});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(PIL it:G2[u]){
			int v=it.first;
			ll w=it.second;
			dis2[s-m][v]=min(dis2[s-m][v],dis2[s-m][u]+w);
			q.push({dis2[s-m][v],v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
//	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		mx=max(mx,k[i]);
		mxk=max(mxk,k[i]);
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(1ll*x);
			t[i].push_back(1ll*y);
			if(T==-1)
			T=1ll*t[i][j];
			else{
				if(T!=t[i][j ]){
					f=0;
				}
			}
		}
	}
//	cout<<mxk<<'\n';
//	cout<<f<<'\n';
	if(n+m<=500){
//		cout<<"oout"; 
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n+m;i++){
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
//				cout<<i+m<<' '<<a[i][j]<<' '<<t[i][j]<<'\n';
				dis[i+m][a[i][j]]=dis[a[i][j]][i+m]=min(t[i][j],dis[i+m][a[i][j]]);
			}
		}
		for(int k=1;k<=n+m;k++){
			for(int i=1;i<=n+m;i++){
				for(int j=1;j<=n+m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
//		cout<<dis[2][3];
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%lld\n",dis[u][v]+w[u]+w[v]);
		}
	}
	else if(f){
//		cout<<q<<'\n';
//cout<<"in\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				G[i+m].push_back(a[i][j]);
				G[a[i][j]].push_back(i+m);
			}
		}
		memset(dis1,0x3f,sizeof(dis1));
		for(int i=1;i<=n;i++){
			bfs(i+m);
		}
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			ll mn=0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<=n;i++){
				mn=min(mn,T*(dis1[i][u]+dis1[i][v])+w[u]+w[v]);
			}
			printf("%lld\n",mn);
		}
	}
	else if(mxk<=2){
		memset(dis1,0x3f,sizeof(dis1));
//		cout<<"in\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				G1[i+m].push_back({a[i][j],t[i][j]});
				G1[a[i][j]].push_back({i+m,t[i][j]});
			}
		}
		for(int i=1;i<=n;i++){
			dijk(i+m);
		}
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			ll mn=0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<=n;i++){
				mn=min(mn,dis1[i][u]+dis1[i][v]+w[u]+w[v]);
			}
			printf("%lld\n",mn);
		}
	}
	else if(n<=2){
		memset(dis2,0x3f,sizeof(dis2));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				G2[i+m].push_back({a[i][j],t[i][j]});
				G2[a[i][j]].push_back({i+m,t[i][j]});
			}
		}
		for(int i=1;i<=n;i++){
			dijk1(i+m);
		}
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			ll mn=0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<=n;i++){
				mn=min(mn,dis2[i][u]+dis2[i][v]+w[u]+w[v]);
			}
			printf("%lld\n",mn);
		}
	}
	return 0;
} 
