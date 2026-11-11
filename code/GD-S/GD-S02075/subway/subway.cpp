#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、 地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[500005];//每个地铁站的地铁口走 到站厅需要的时间
int a,t[505][500005];
vector<pair<int,int>> g[500005];
int dfs(int step,int to,int altime,int whiclu){
	for(auto s : g[step]){
		if(s.first==to){
			return altime;
		}
		if(s.second==whiclu){
			 return dfs(s.first,to,altime,whiclu);
		}
		else if(s.second!=whiclu){
			return dfs(s.first,to,altime+t[whiclu][s.first]+t[s.second][s.first],s.second);
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;//第 i 条线路经过的地铁站数
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t[i][j];// ai,1,ti,1,ai,2,ti,2,...,ai,ki,ti,ki，
			     			//其 中 ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示
				 			//从该地铁站的站厅走到第 i 条线 路的站台需要的时间。
			if(j!=1){
				g[j].push_back({a,j});
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x];
		ans+=dfs(x,y,ans,0);
		ans+=w[y];
		cout<<ans<<'\n';
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
