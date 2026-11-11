#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int w[500005];
int k[505];
vector<int> a[505];
vector<int> t[505];
vector<int> lu[500005];
int c,n,m,d,q;
bool vis[500005];

void dfs(int xr,int yr,int time){
	for(int j = 1;j<=lu[xr][0];j++){//地铁站xr
		//第 lu[i][j] 条线路经过的第 i 个地铁站
		
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//测试点编号c、地铁线路数n、地铁站数m、每个地铁站最多被几条线路经过d,以及出行计划数q
	cin>>c>>n>>m>>d>>q;
	if(1){//特殊性质 B
		for(int i = 1;i<=m;i++){
			cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间
		}
		for(int i = 1;i<=n;i++){
			cin>>k[i];//第 i 条线路经过的地铁站数
			for(int j = 1;j<=k[i];j++){
				//a[i][j]表示第 i 条线路经过的第 j 个地铁站,
				//t[i][j]表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
				cin>>a[i][j]>>t[i][j];
				//lu[i][j]表示第 lu[i][j] 条线路经过的第 i 个地铁站,
				lu[j][++lu[j][0]]=i;
			}
		}
		int xr,yr;
		while(q--){
			memset(vis,0,sizeof(vis));
			cin>>xr>>yr;//起点和终点所在的地铁站编号
			dfs(xr,yr,0);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
