#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dis;
int ans=INT_MAX;
void dfs(vector<vector<int>> &tai,vector<vector<pair<int,int>>> &xian,int now,int fin,int time){//当前站点 
	if(now==fin){
		ans=min(ans,time);
	}
	for(auto v:tai[now]){//当前站厅选路线 
		for(auto u:xian[v]){//当前路线选下一个站台 
			if(u.first==now)continue;
			if(dis[u.first]==0){
				dfs(tai,xian,u,fin,time+u.second+xian[now].second);//默认直接回到下一个的站厅 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;//测试点编号
	int n,m;//地铁线数量，地铁站数量 
	int d,q;//每个地铁站被几条线路经过,几个行程规划
	cin>>c>>n>>m>>d>>q;
	vector<int> t0(m);//从地铁口走到站厅的时间
	for(int i=0;i<m;i++){
		cin>>t0[i];
	} 
	dis.resize(n,vector<int>(m,0));
	vector<vector<pair<int,int>>> xian(n);//i线路的编号为x的耗时y 
	vector<vector<int>> tai(m);//有多少线路经过该站台 
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		while(x--){
			int ax,tx;
			cin>>ax>>tx;
			tai[ax].push_back(i);
			xian[i].push_back({ax,tx});
		}
	}
	for(int i=0;i<q;i++){
		int str,fin;
		cin>>str>>fin;
		if(str==fin)cout<<0<<"\n";
		dfs(tai,xian,str,fin,t0[str-1]);
	}
	cout<<flush;
	return 0;
}
