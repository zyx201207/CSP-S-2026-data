#include<bits/stdc++.h>
using namespace std;
const int inf=1e8+5;
int dis[505][505];
struct edge{
	int v,w;
};
vector<edge>g[505];
void floyd(){
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dis[i][j]=inf;
		}
	}
	for(auto i:g){
		for(auto j:i){
			dis[i][j.v]=dis[j.v][i]=min(dis[i][j.v],j.w);
			for(auto k:g[j.v]){
				dis[i][k.v]=dis[k.v][i]=min(dis[i][k.v],dis[i][j.v]+dis[j][k.v]);
			}
		}
	}
}
int w[100005],k[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		g[i].push_back({i+n,w[i]});
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			g[i].push_back();
		}
	}
	
}
/*

nn*m=1;

*/
