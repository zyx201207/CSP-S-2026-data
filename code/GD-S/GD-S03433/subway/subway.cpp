#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int dis[1010];
int dis1[1010][1010];
int w[N];
int dis3[N];
int c,n,m,d,q;
int k[N];
int a[1010][1010];
int u[N],v[N];
struct node{
	int id,val;
	bool operator<(const node &u)const{
		return val>u.val;
	}
};
int vis[1010];
vector<int>g[N];
void djs(int st){
	priority_queue<node>q;
	q.push({st,0});
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st]=0;
	while(q.size()){
		node t=q.top();
		q.pop();
		
		for(int p=1;p<=1000;p++){
			if(t.id==p)continue;
			if(a[t.id][p]!=inf){
				if(dis[p]>dis[t.id]+a[t.id][p]&&vis[p]==0){
	//				cout<<a[t.id][p]<<'\n';
					vis[p]=1;
					dis[p]=dis[t.id]+a[t.id][p];
					q.push({p,dis[p]});
				}
			}
		}
		
	}
	
	for(int i = 1;i<=m;i++){
		dis1[st][i]=dis[i];
	//	cout<<dis[i]<<'\n';
	}
}

void init(){
	for(int i = 1;i<=m;i++){
		djs(i);
	}
}
int sum=0;
int vis1[N];

void bfs(int x,int y){
	for(int i = 1;i<=20500;i++){
		vis1[i]=0;
	}	
	for(int i = 1;i<=20500;i++){
		dis3[i]=0;
	}
	vis1[x]=1;
	queue<int>q;
	q.push(x);
	while(q.size()){
		int t=q.front();
		q.pop();
		
		for(auto u:g[t]){
			if(vis1[u])continue;
			vis1[u]=1;
			q.push(u);
			dis3[u]=dis3[t]+1;
		}
	}
	int p1 = 0;
	for(int i=1;i<=m;i++){
		p1+=vis1[i];
	}

//	cout<<dis3[y]<<"\n";
	cout<<dis3[y]*sum+w[x]+w[y]<<'\n';
	
}

void sol(){
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u[j]>>v[j];
			sum=v[j];
			g[i+m].push_back(u[j]);
			g[u[j]].push_back(i+m);
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		
		bfs(x,y);
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	if(c>=12&&c<=15){
		sol();
		return 0;
	}
	for(int i = 1;i<=1000;i++){
		for(int j = 1;j<=1000;j++){
			a[i][j]=inf;
		}
	}
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u[j]>>v[j];
		}
		for(int j = 1;j<=k[i];j++){
			for(int l = 1;l<j;l++){
				a[u[j]][u[l]]=min(a[u[j]][u[l]],v[l]+v[j]);
				a[u[l]][u[j]]=min(a[u[l]][u[j]],v[l]+v[j]);
			}
		}
	}
	init();
	

	while(q--){
		int st,ex;
		cin>>st>>ex;
		
		cout<<dis1[st][ex]+w[st]+w[ex]<<'\n';	
	}
	
	
	return 0;
}
