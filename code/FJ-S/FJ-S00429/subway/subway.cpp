#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int maxn=507;

int w[maxn],k[maxn],a[maxn][maxn],t[maxn][maxn],f[maxn][maxn],ans=inf;
bool vis[maxn];
vector<int>v[maxn];

void dfs(int x,int y,int s,int last,bool ok){// 当前点 终点 距离 乘哪条线来的 上一个点
	if(s>ans)return;
	if(x==y){
		ans=min(ans,s+f[x][last]);
		return;
	}
	for(auto i:v[x]){ // 穿过这个点的路线 
	 	if(i==last){
			for(int j=1;j<=k[i];j++){
				int nx=a[i][j];
				if(vis[nx])continue;
				if(!ok){
					vis[x]=1;
					dfs(nx,y,s+f[x][i],i,1);
				}
				else {
					vis[x]=1;
					dfs(nx,y,s,i,1);
				}
			}
		}
		else {
			for(int j=1;j<=k[i];j++){
				int nx=a[i][j];
				if(vis[nx])continue;
				if(!ok){
					vis[x]=1;
					dfs(nx,y,s+f[x][last]+f[nx][last]+f[nx][i],i,1);
				}
				else {
					vis[x]=1;
					dfs(nx,y,s+f[nx][last]+f[nx][i],i,1);
				}
			}
		}
	}	
	vis[x]=0;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[a[i][j]][i]=t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		int x,y;
		cin>>x>>y;
		ans=inf;
		dfs(x,y,0,0,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
