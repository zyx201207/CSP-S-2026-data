#include<iostream>
#include<vector>
const int M=5*1e4+5,N=5*1e2+5;
using namespace std;
int w[M];
int kkk[N];
int a[N][M],t[N][M];
int dp[N][N];
vector<int> G[M];
vector<pair<int,int> > zhongzhuan[N];
bool vis[N];
void dfs(int x,int ans){
	vis[x]=1;
	for(int i=0;i<zhongzhuan[x].size();i++){
		if(!vis[zhongzhuan[x][i].first]){
			dp[x][zhongzhuan[x][i].first]=ans+zhongzhuan[x][i].second;
			dfs(zhongzhuan[x][i].first,ans+zhongzhuan[x][i].second);
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kkk[i];
		for(int j=1;j<=kkk[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			G[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(!G[i].empty())
			if(G[i].size()>1){
				for(int j=0;j<G[i].size();j++){
					for(int kk=0;kk<j;kk++){
						zhongzhuan[G[i][j]].push_back({G[i][kk],(t[G[i][j]][i]+t[G[i][kk]][i])});
						zhongzhuan[G[i][kk]].push_back({G[i][j],(t[G[i][kk]][i]+t[G[i][j]][i])});
					}
				}
			}
	}
	dfs(1,0);
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=0x3f3f;
		for(int i=0;i<G[x].size();i++){
			for(int j=0;j<G[y].size();j++){
				minn=min(minn,dp[G[x][i]][G[y][j]]+t[G[x][i]][x]+t[G[y][j]][y]);
			}
		}
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
