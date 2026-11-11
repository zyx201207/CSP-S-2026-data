//张仕林 GZ-S00049 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];//每个地铁站的地铁口走到站厅需要的时间
struct Line{
	int pass;//第 i 条线路经过的地铁站数
	int point[505];//第 i 条线路经过的第 j 个地铁站
	int time[505];//从该地铁站的站厅走到第 i 条线路的站台需要的时间
}l[505];
//c测试点编号, n地铁线路数量, m地铁站数, d每个地铁站最多被几条线路经过, q出行计划数 ，
int th[505]={0};//经过的地铁站 
int ans=100000000;
int dfs(int s,int e,int now,int t,int line){
	if(e==now){
		t+=w[e];
		return t;
	}
	if(s==now){
		if(line==0){
			t+=w[s];
			th[s]=1;
			for(int i=1;i<=n;++i){//指派线路 
				if(l[i].point[s]!=0){
					int cp=dfs(s,e,now,t,line);
					if(ans>cp)return cp;
					else return ans;
				}
			}
		}else{
			for(int i=1;i<=l[line].pass;++i){//遍历站点 
				if(th[now]!=1&&l[line].point[i]==1){//没去过并且线路经过 
					for(int j=1;j<=n;++j){//遍历线路 
						if(l[j].point[now]!=0){
							int cp=dfs(s,e,i,t+l[line].time[i],j);
							if(ans>cp)return cp;
							else return ans;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=l[line].pass;++i){//遍历站点 
		if(th[now]!=1&&l[line].point[i]==1){//没去过并且线路经过 
			for(int j=1;j<=n;++j){//遍历线路 
				if(l[j].point[now]!=0){
					int cp=dfs(s,e,i,t+l[line].time[i],j);
					if(ans>cp)return cp;
					else return ans;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&l[i].pass);
		for(int j=1;j<=l[i].pass;++j){
			scanf("%d %d",&l[i].point[j],&l[i].time[j]);
		}
	}
	int x,y;//起始点-目的地 
	for(int i=1;i<=q;++i){
		scanf("%d %d",&x,&y);
		printf("%d\n",dfs(x,y,x,0,0));
	}
	return 0;
}
