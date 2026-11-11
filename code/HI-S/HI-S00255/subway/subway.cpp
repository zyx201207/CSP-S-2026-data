#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c;//测试点号 
int m,n;//m个地铁站,n条铁路 
int d;//每个地铁站最多被几条线路经过
int r;//出行计划数
int a[505][25],t[505][25],x,y,k[505],ans=-1;
map<int,int> mp; 
/*void dfs(int id,int time){
	if(id==y){
		ans=min(ans,time);
		return ;
	}for(int i=0;i<k[id];i++){
		
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	int w[m],time[m];
	for(int i=0;i<m;i++)cin>>w[i]; 
	//从每个地铁站走到站厅需要的时间。
	for(int i=0;i<n;i++){
		cin>>k[i];//第i条线路经过的地铁站数
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]]=t[i][j]; 
			int c=a[i][j];
			time[c]=t[i][j];
			//a[i][j]第i条线路经过的地铁站
			//t[i][j]从该地铁站的站厅走到第i条线
			//路的站台需要的时间。
		}
			
	}for(int i=0;i<r;i++){
		cin>>x>>y;//起点x和终点y所在的地铁站编号
		cout<<w[y]+w[x]+mp[x]+mp[y]<<"\n";
	}
	return 0;
}/*
w1+t1,1 +(t1,2+t2,2)+(t2,3+t3,3)+t3,6+w6=35
走1个地铁站的地铁口走到站厅,到第1条线路的站台，
第2个地铁站走回站厅，再走到第2条线路的站台，
第3个地铁站走回站厅，再走到第3条线路的站台
第6个地铁站后走回站厅，后走到第6个地铁站的地铁口，

 地铁站  地铁口->站厅->站台
			  w[i]  t[i][j] 
			  

*/
