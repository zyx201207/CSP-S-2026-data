#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,t,n,m,dp[N][N],de[N],ans,vis[N][N],sz[N],p[N],id[N],tot;
vector<int>v[N];
void dfs2(int x,int y){
	de[x]=de[y]+1;
	for(int i:v[x]){
		if(i!=y)dfs2(i,x); 
	}
}
void dfs(int x,int y){
	for(int i=1;i<=n;i++)dp[x][i]=1e9;
	sz[x]=1,dp[x][0]=1,dp[x][1]=0,id[x]=++tot;
	for(int i:v[x]){
		if(i==y)continue;
		dfs(i,x);
		dp[x][0]=max(dp[x][0],dp[i][0]+1);
		for(int j=1;j<=sz[x];j++)p[j]=dp[x][j],dp[x][j]=1e9;
		for(int j=1;j<=sz[x];j++){
			for(int k=0;k<=sz[i];k++)dp[x][j+k]=min(dp[x][j+k],max(p[j],dp[i][k]));
		}
		sz[x]+=sz[i];
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=n;
	for(int i=1;i<=n;i++){
		dfs2(i,0);
		for(int j=1;j<=n;j++)vis[i][j]=de[j]-1;
	}
	for(int i=1;i<=n;i++){
		tot=0;
		dfs(i,0);
		for(int j=1;j<=n;j++){
			int as1=dp[j][min(sz[j],m)];
			for(int k=1;k<=n;k++){
				if(id[k]>=id[j]&&id[k]<id[j]+sz[j])continue;
				as1=max(as1,vis[k][j]);
				if(id[j]>=id[k]&&id[j]<id[k]+sz[k])continue;
				int as2=n;
				for(int o=1;o<=min(sz[j],m-1);o++){
					as2=min(as2,max(dp[j][o],dp[k][min(sz[k],m-o)]));
				}
				for(int o=1;o<=n;o++){
					if(id[o]>=id[j]&&id[o]<id[j]+sz[j])continue;
					if(id[o]>=id[k]&&id[o]<id[k]+sz[k])continue;
					as2=max(as2,min(vis[o][j],vis[o][k]));
				}
				ans=min(ans,as2);
			}
			ans=min(ans,as1);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
//I guess I will get 330pts and go to WC2027.
//If I can't do this,maybe I will retired when NOIP2026 over.
//Because I'm in senior 2 and I got NOIP 1= last year.
//So if I don't write this word now,I will have no choice to do this. 
//My English is too weak to write too long.
//I think the word I write isn't "no have contact with this competition".
//csps2026 rp++
