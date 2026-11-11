#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
int m,n,c;
int d;//每个地铁站最多有d条线路经过 
int isd[MAXN][505];//地铁站i是否被线路k经过 
int vis[505][MAXN];//线路k上的节点i是否被遍历过 
int q;//q个出行计划 
int w[MAXN];
int k[MAXN];//第i条线路经过k[i]个地铁站
int a[MAXN][MAXN];
int t[MAXN][MAXN]; 
ll ans=0x3f;
ll minn(ll x,ll y){return x>y?y:x;}
ll absn(ll x){return x>0?x:-x;}
void dfs(int now,int end,int value,int layer){

	if(now==end){
		ans=minn(ans,value+w[end]);
	}
	for(int i=1;i<=k[layer];i++){//枚举从这条线路上到达的地铁站 
		int next=a[layer][i];
		for(int j=1;j<=n;j++){//枚举目标地铁站所能转的线路 
			if(!vis[j][next]&&isd[next][j]){
				vis[j][next]=1;
				dfs(next,end,value+t[j][next],j);
				vis[j][next]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			isd[ a[i][j] ][ i ]=1;
			  
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		ans=0x3f;
		memset(vis,sizeof(vis),0);
		for(int i=1;i<=n;i++){
			if(isd[x][i]){
				vis[i][x]=1;
				dfs(x,y,w[x]+t[i][x],i);
				vis[i][x]=0;
			}
		}
		cout<<ans<<endl; 

	}
	return 0;
}



