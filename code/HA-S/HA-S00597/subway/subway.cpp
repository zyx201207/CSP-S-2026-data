#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+10;
const int M=5e5+10;
const ll INF=1e18;
int p,m,n,d,q;
ll dis[N][N];
ll w[M];
struct node{
	int id,sum;
};
vector <node> e[M];
void floyd(){
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]!=INF&&dis[k][j]!=INF){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
			dis[j][i]=dis[i][j];
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>p>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int x,y,z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			e[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				dis[e[i][j].id][e[i][k].id]=min(dis[e[i][j].id][e[i][k].id],(ll)e[i][j].sum+e[i][k].sum);
				dis[e[i][k].id][e[i][j].id]=min(dis[e[i][k].id][e[i][j].id],(ll)e[i][j].sum+e[i][k].sum);
			}
		}
	}
	floyd();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ll res=INF;
		for(int j=0;j<e[x].size();j++){
			for(int k=0;k<e[y].size();k++){
				int u=e[x][j].id,u1=e[x][j].sum;
				int v=e[y][k].id,v1=e[y][k].sum;
				res=min(res,dis[u][v]+u1+v1+w[x]+w[y]);
			}
		}
		cout<<res<<'\n';
	}
}
//16:19 通过全部大洋里 
//16：27 对拍好难写 
