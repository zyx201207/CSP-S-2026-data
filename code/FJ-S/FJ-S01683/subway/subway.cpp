#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[505][500005];
int graph[5005][5005];
bool online[505][500005];
void other(){
	for(int i=1;i<=n;i++){
		int k,a,tmp;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>tmp;
			online[i][a]=1;
			t[i][a]=tmp;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				for(int x=1;x<=n;x++)
					if(online[x][i] && online[x][j])
						graph[i][j]=t[x][i]+t[x][j];
}
void taskA(){
	for(int i=1;i<=n;i++){
		int k,w1,w2,u,v;
		cin>>k>>u>>w1;
		if(k<2) continue;
		cin>>v>>w2;
		graph[u][v]=graph[v][u]=w1+w2;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(graph,0x3f,sizeof(graph));
	if(c>=9 && c<=11) taskA();
	else other();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+graph[x][y]<<endl;
	}
	return 0;
}
// 字体 -> Wingdings
// 《 这 下 看 懂 了 》
