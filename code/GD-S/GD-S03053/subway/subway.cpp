#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,n,m,d,q,w[N],k[N],dist[10010][10010];
struct node{
	int a,v;
}p[N];
void spfa(){
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>p[j].a>>p[j].v;
		}
		for(int x=1;x<=k[i];x++){
			for(int y=x+1;y<=k[i];y++){
				dist[p[x].a][p[y].a]=dist[p[y].a][p[x].a]=min(dist[p[x].a][p[y].a],p[x].v+p[y].v);
			}
		}
	}
	spfa();
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
