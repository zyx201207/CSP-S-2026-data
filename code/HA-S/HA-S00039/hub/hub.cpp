#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9;
int a[500010];
int dis[5100][5100];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,maxn=1;
		cin>>n>>k;
		for(int i=1;i<=5000;i++){
			for(int j=1;j<=5000;j++){
				if(i==j)dis[i][j]=0;
				else dis[i][j]=INF;
			}
		}
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			dis[u][v]=1;
			dis[v][u]=1;
		}
	
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]!=INF)maxn=max(maxn,dis[i][j]);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
