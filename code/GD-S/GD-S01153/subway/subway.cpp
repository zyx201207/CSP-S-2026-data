#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;  /*测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数*/
int w[500005]; /*地铁站口与站厅距离*/
int k[505]; /*线路站点数*/ 
int mp[505][505];
int dis[505][505];
int plan[100005][2];

int findway(int in_station){
	int way_return = 0;
	
	return(way_return);
}

void tackleA(int x){
	int stp,fnp;
	stp = plan[x][1];
	fnp = plan[x][2];
	int total = w[stp] + w[fnp];
	
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q; /*获取测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数*/
	for(int i=1;i<=m;i++){ /*获取地铁站口与站厅距离*/
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){ 
		cin >> k[i];/*获取线路地铁站数*/
		for(int j=1;j<=k[i];j++){
			cin >> mp[i][j] >> dis[i][j]; /*获取线路地铁站与该地铁站该线站台与站厅距离*/
		}
	}
	for(int i=1;i<=q;i++){
		cin >> plan[i][1] >> plan[i][2]; /*获取计划起终点*/
	}
	
	for(int i=1;i<=q;i++){
		if(c>=7||c<=11) tackleA(i); 
	}
	return 0;
}
