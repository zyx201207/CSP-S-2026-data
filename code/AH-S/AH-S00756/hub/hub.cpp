#include<bits/stdc++.h>
using namespace std;
int dis[105][105];
int n,k;
int cnt[1000005];
vector<int>ve[100005];
int l=0;
int id[100005];
bool vis[15];
int getsum(int r,int t){
	int sum=0;
	if(vis[r]&&!vis[t])sum++;
	for(int i=0;i<(int)ve[r].size();i++){
		int rv=ve[r][i];
		if(rv!=t){
			sum+=getsum(rv,r);
		}
	}
	return sum;
}
int c,t;
int ans;
int u,v;
void dfs(int x,int r,int fa,int dep){
	dis[x][r]=dep;
	for(int i=0;i<(int)ve[r].size();i++){
		int rv=ve[r][i];
		if(rv!=fa){
			dfs(x,rv,r,dep+1);
		}
	}
}
int getdis(int x){
	int ans=0;
	for(int j=1;j<=n;j++){
		int minn=0x3f3f3f3f;
		for(int i=1;i<=l;i++){
			minn=min(minn,dis[id[i]][j]);
		}
		ans=max(ans,minn);
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=(1<<13)-1;i++){
		if(i&1)cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i>>1];
	}
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dfs(i,i,0,0);
		}
		for(int i=0;i<(1<<n);i++){
			if(cnt[i]!=k)continue;
			l=0;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					id[++l]=j;
					vis[j]=1;
				}
			}
			if(getsum(1,0)<=2){
				ans=min(ans,getdis(i));
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			ve[i].clear();
		}
	}
	return 0;
}
