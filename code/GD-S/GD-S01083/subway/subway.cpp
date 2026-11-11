#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
int cc1(int x){
	int cnt=0;
	int xx=x;
	while(xx!=0){
		xx/=10;
		cnt++;
	}
	return pow(10,cnt)+x;
}
int cc2(int x){
	int cnt=0;
	int xx=x;
	while(xx!=0){
		xx/=10;
		cnt++;
	}
	return pow(10,cnt)*2+x;
}
int cc3(int x){
	int cnt=0;
	int xx=x;
	while(xx!=0){
		xx/=10;
		cnt++;
	}
	return pow(10,cnt)*3+x;
}
struct gr{
	int v,w;
};
vector<gr> g[4000];
queue<int> q;
int dis[400010];
bool vis[400010];
void rp(int s){
	for(int i=1;i<=400001;i++){
		vis[i]=0;
		dis[i]=1e9;
	}
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		int u=cc1(i);
		int v=cc2(i);
		g[v].push_back({u,w});
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int v=cc3(i);
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			int u=cc2(a);
			g[u].push_back({v,t});
			g[v].push_back({u,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		x=cc1(x);
		y=cc1(y);
		rp(x);
		cout<<dis[y]<<endl;
	}
	return 0;
} 
