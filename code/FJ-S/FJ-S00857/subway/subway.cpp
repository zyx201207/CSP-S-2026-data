#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
struct App{
	int v,w;
};
vector<App> g[N];
int c,n,m,d,q;
int a[N],t[N];
int w[N];
void biuld_(int k){
	for(int i=1;i<=k;i++){
	    for(int j=i+1;j<=k;j++){
//	    	int num1=g[a_[i]][a_[j]].t;
//	    	int num2=g[a_[j]][a_[i]].t;
//	    	cout<<num1<<' '<<num2<<'\n';
			g[a[i]].push_back({a[j],t[i]+t[j]});
			g[a[j]].push_back({a[i],t[i]+t[j]});
		}
	}
}
void dijakstr(int s){
	priority_queue<int,vector<int>,greater<int> > pq;
	pq.push(s);
	bool vis[N]={};
	vis[s]=1;
	while(!pq.empty()){
		int u=pq.top();
		pq.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			if(!vis[v]){
				pq.push(v);
				vis[v]=1;
			}
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(w>t[u]+t[v]){
				g[u][i].w=t[u]+t[v];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
//		memset(a_,0,sizeof(a_));
//		memset(t_,0,sizeof(t_));
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		biuld_(k);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijakstr(x);
		cout<<w[x]+g[x][y].w+w[y]<<'\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
