#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,M=1005,inf=1e18;
int C,n,m,d,Q,w[M],k[N],a[N][M],t[N][M];

int disX[M][M];
vector<pair<int,int>>eX[M];
void X(int s){
	bool vis[1005];
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	disX[s][s]=0;
	while(!q.empty()){
		int u=q.top().second;
		if(vis[u])continue;
		vis[u]=1;
		q.pop();
		for(auto [v,w]:eX[u]){
			if(disX[s][v]>disX[s][u]+w){
				disX[s][v]=disX[s][u]+w;
				q.push({disX[s][v],v});
			}
		}
	}
}

signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;	
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	if(m<=1000){//44
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[i];l++){
					if(j==l)continue;
					eX[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
					eX[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
				}
			}
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				disX[i][j]=inf;
		for(int i=1;i<=m;i++)	
			X(i); 
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<disX[x][y]+w[x]+w[y]<<"\n";
		}
	}
	if(n==2){
		while(Q--){
			int x,y;
		}
	}
	return 0;
}
