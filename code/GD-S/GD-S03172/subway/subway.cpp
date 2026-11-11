#include <bits/stdc++.h>
using namespace std;
const int N=405,M=5e5+10;
int dis[N][N],w[M],c,n,m,d,q,a[M],t[M],p[N][N][N];
vector<pair<int,int>> g[M];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int x=1;x<=m;x++){
				for(pair<int,int> y:g[x]){
					for(pair<int,int> o:g[x]){
						int t=y.first,k=o.first; 
						if(t==k||p[0][t][i]==0||p[k][0][j]==0)continue;
						if(dis[i][x]+p[t][k][x]+dis[x][j]+p[0][t][i]+p[k][0][j]<dis[i][j]){
							dis[i][j]=min(dis[i][j],dis[i][x]+p[t][k][x]+dis[x][j]+p[0][t][i]+p[k][0][j]); 
						}
//						if(i==1&&j==2)cout<<x<<" "<<p[0][t][i]<<" "<<p[k][0][j]<<" "<<dis[i][j]<<"\n";
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[a[j]].push_back({i,t[j]});
			for(int x=1;x<j;x++){
				dis[a[x]][a[j]]=0;
				dis[a[j]][a[x]]=0;
			}
			for(pair<int,int> v:g[a[j]]){
				int ta=v.first,tb=v.second;
				p[i][ta][a[j]]=tb+t[j];
				p[ta][i][a[j]]=tb+t[j];
			}
			p[0][i][a[j]]=t[j];
			p[i][0][a[j]]=t[j];
//			cout<<p[0][i][a[j]]<<" "<<i<<" "<<a[j]<<"\n";
//			g[a[j]].push_back({0,0}); 
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(dis[x][y]==0){
			bool vis[N]={};
			for(pair<int,int> i:g[x]){
				vis[i.first]=1;
			}
			for(pair<int,int> i:g[y]){
				if(vis[i.first]){
					cout<<dis[x][y]+w[x]+w[y]+p[0][i.first][x]+p[i.first][0][y]<<"\n";
				}
			}
		}
		else cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 
