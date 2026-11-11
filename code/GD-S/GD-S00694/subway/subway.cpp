#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans,w[500005],a[205],b[205][5005],t[205][5005],xx,yy,g;
bool use[5005][4][205],f[205][5005];
void dfs(int x,int v,int k,int u){
	if(k>=ans) return;
	if(x==yy&&v==1){
	    ans=k;
	    return;
	}
	if(x==yy&&v==3){
		use[x][2][0]=1;
		dfs(x,2,k+t[u][x],0);
		use[x][2][0]=0;
	}
	if(x==yy&&v==2){
		use[x][1][0]=1;
		dfs(x,1,k+w[x],0);
		use[x][1][0]=0;
	}
	if(v==1){
		if(!use[x][2][0]){
			use[x][2][0]=1;
			dfs(x,2,k+w[x],0);
		    use[x][2][0]=0;
		}
	}
	if(v==2){
		if(!use[x][1][0]){
			use[x][1][0]=1;
			dfs(x,1,k+w[x],0);
			use[x][1][0]=0;
		}
		for(int i=1;i<=n;i++){
			if(f[i][x]&&(!use[x][3][i])){
				use[x][3][i]=1;
				dfs(x,3,k+t[i][x],i);
				use[x][3][i]=0;
			} 
		}
	}
	if(v==3){
		if(!use[x][2][0]){
			use[x][2][0]=1;
			dfs(x,2,k+t[u][x],0);
			use[x][2][0]=0;
		}
		for(int i=1;i<=a[u];i++){
			if(!use[b[u][i]][3][u]){
				use[b[u][i]][3][u]=1;
				dfs(b[u][i],3,k,u);
				use[b[u][i]][3][u]=0;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cin>>b[i][j]>>t[i][b[i][j]];
			f[i][b[i][j]]=1;
		}
	}
	while(q--){
		cin>>xx>>yy;
		ans=LLONG_MAX;
		memset(use,0,sizeof(use));
		use[xx][1][0]=1;
		dfs(xx,1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
