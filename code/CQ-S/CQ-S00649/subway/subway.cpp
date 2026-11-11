//桃李不言下自成蹊 
//In 2026,I finally brave enough to say I love you 161025
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q;
//n地铁线路数
//m地铁站数
//d每个地铁站最多被几条线路经过
//q出行计划数
vector<vector<int>> ve;
struct node{
	int id;//站台编号 
	vector<pair<int,int>> ti;//对于x号线的node站从大厅到站台要y时间 
	int w;//从站口到大厅的时间 
}a[N];  
pair<int,int> check(int x,int y){
	int len1=a[x].ti.size();
	int len2=a[y].ti.size();
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(a[x].ti[i].first==a[y].ti[j].first){
				return {i,j};
			}
		}
	}
}
int st,ed;
int mn;
void dfs(int u,int fa,int sum){
	if(u==ed){
		mn=min(mn,sum);
		return;
	}
	for(auto v:ve[u]){
		if(v!=fa){
			pair<int,int> res=check(v,ed);
			if(res.second!=-1){
				dfs(ed,-1,sum+a[ed].ti[res.second].second+a[ed].w);
			} 
			dfs(v,u,sum);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ve.resize(n);
	for(int i=1;i<=m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int k,x,y,la;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;	
			a[x].ti.push_back({i,y}); 
			ve[x].push_back(la);
			ve[la].push_back(x);
			la=x;
		}
	}
	while(q--){
		cin>>st>>ed;
		pair<int,int> res=check(st,ed);
		cout<<a[st].ti[res.first].second+a[st].w+a[ed].ti[res.second].second+a[ed].w<<'\n';
	}
	return 0;
}
