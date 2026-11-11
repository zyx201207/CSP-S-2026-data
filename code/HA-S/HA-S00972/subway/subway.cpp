#include <bits/stdc++.h>
using namespace std;
int C,n,m,d,q,w[500005],k[500],a[500][500005],t[500][500005],sum[1005];
vector<int> ve[1005];
/*
输入的第一行包含五个非负整数 c, n,m, d, q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例。
输入的第二行包含 m 个正整数 w1,w2, . . . ,wm，依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2ki 个正整数，其中第一个正整数为 ki，表
示第 i 条线路经过的地铁站数；接下来 2ki 个正整数为 ai,1, ti,1, ai,2, ti,2, . . . , ai,ki
, ti,ki
，其
中 ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 xr, yr，分别表示第 r 个出行计
划的起点和终点所在的地铁站编号。
*/
int d1[1005][1005];
bool f[1005];
void dfs(int x){
	if (f[x]==1) return;
	for(int yy=1;yy<=sum[x];yy++){
		int y=ve[x][yy];
		for (int i=1;i<=k[y];i++){
			if (a[y][i]!=x){
				if (d1[x][a[y][i]]>(t[y][a[y][i]]+t[y][x])){
					d1[x][a[y][i]]=t[y][a[y][i]]+t[y][x];
					d1[x][a[y][i]]=d1[a[y][i]][x];
				}
			}
		}
	}
	f[x]=1;
	for(int yy=1;yy<=sum[x];yy++){
		int y=ve[x][yy];
		for (int i=1;i<=k[y];i++){
			if (a[y][i]!=x){
				dfs(a[y][i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	memset(a,-1,sizeof(a));
	memset(f,-1,sizeof(f));
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ve[a[i][j]].push_back(i);
			sum[a[i][j]]++;
			t[i][a[i][j]]=t[i][j];
			t[i][j]=-1;
		}
	}
	if (C>=7 && C<=11){
		
		memset(d1,0x3f,sizeof(d1));
		int v,u;
		for (int i=1;i<=m;i++){
			dfs(i);
		}
		for (int u=1;u<=n;u++){
			for (int v=1;v<=u;v++){
				for (int k=1;k<=n;k++){
					d1[u][v]=min(d1[u][k],d1[k][v]);
					d1[v][u]=d1[u][v];
				}
			}
		}
		int x,y;
		for (int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<d1[x][y];
		}
	}
}
