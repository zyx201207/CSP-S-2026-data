#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int pt;//站点编号 
	int wh;//属于哪一条路线 
};
int c,n,m,d,p;
ll w[505];
int lth;//---
int a[505][505];
ll t[505][505];
vector<int>ty[505];//站点属于那些路线
ll tgo[505][505];//站点i在j路线中到站厅的步行时间 
vector<node>g[505];
ll ans[505][505];//
priority_queue<pair<ll,pair<int,int> > >pq;//distance,(point,路线) 
bool vis[505];
void djs(int s,int uut){
	//以s为起点从第ut路线到达其他点
	pq.push({tgo[s][uut],{s,uut}});
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	//cout<<"RESTART:\n";
	while(!pq.empty()){
		int nw=pq.top().second.first;
		ll dis=pq.top().first;
		int ut=pq.top().second.second;
		pq.pop();
		//cout<<nw<<':'<<dis<<' '<<ut<<'\n';
		for(int i=0;i<g[nw].size();i++){
			if(!vis[g[nw][i].pt]){
				//cout<<"   "<<g[nw][i].pt<<'\n';
				if(g[nw][i].wh==ut){
					//同一条路线上
					pq.push({tgo[g[nw][i].pt][g[nw][i].wh]+dis,{g[nw][i].pt,g[nw][i].wh}});
					ans[s][g[nw][i].pt]=min(ans[s][g[nw][i].pt],tgo[g[nw][i].pt][g[nw][i].wh]+dis);
				}else{
					//不同路线
					pq.push({tgo[nw][g[nw][i].wh]+tgo[g[nw][i].pt][g[nw][i].wh]+dis,{g[nw][i].pt,g[nw][i].wh}});
					ans[s][g[nw][i].pt]=min(ans[s][g[nw][i].pt],tgo[nw][g[nw][i].wh]+tgo[g[nw][i].pt][g[nw][i].wh]+dis);
				}
				vis[g[nw][i].pt]=1;
			}
			
		}
	}
	return ;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			ty[a[i][j]].push_back(i);
			tgo[a[i][j]][i]=t[i][j];
			if(j>1){
				g[a[i][j-1]].push_back({a[i][j],i}); 
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=999999999;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ty[i].size();j++){
			djs(i,ty[i][j]);
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
