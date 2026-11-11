#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],t,k,a,x,y,mp[505][500005],ans[500005],k2=0;
bool vis[500005];
inline void dfs(int now,int end,int tim){
	if(now==end){
		ans[++k2]=tim;
		return;
	}
	for(int i=1;i<=n;i++){
		if(mp[i][now]!=0){
			for(int j=1;j<=m;j++){
				if(mp[i][j]!=0&&!vis[j]){
					vis[j]=1;
					dfs(j,end,tim+mp[i][j]+mp[i][now]);
					vis[j]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			mp[i][a]=t;
		}
	}
	while(q--){
		cin>>x>>y;
		vis[x]=1;
		dfs(x,y,0);
		int mi=99999999;
		for(int i=1;i<=k2;i++){
			mi=min(mi,ans[i]);
		}
		cout<<mi+w[x]+w[y]<<endl;
		memset(vis,0,sizeof(vis));
		k2=0;
	}
	return 0;
}
//CCF CSP-S T2subway
