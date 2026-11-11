#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[20005],k[505],a[505][20005],t[505][20005],mn=1e9,ans=0;
bool vis[20005];
void dfs(int x,int y,int z){
	if(x==y){
		mn=min(mn,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==z) continue;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				ans+=t[i][j];
				for(int kk=1;kk<=k[i];kk++){
					if(vis[a[i][kk]]) continue;
					vis[a[i][kk]]=1;
					ans+=t[i][kk];
					dfs(a[i][kk],y,i);
					ans-=t[i][kk];
					vis[a[i][kk]]=0;
				}
				ans-=t[i][j];
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1,x,y;i<=q;i++){
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		mn=1e9,ans=0;
		vis[x]=1;
		dfs(x,y,0);
		cout<<mn+w[x]+w[y]<<"\n";
	}
	return 0;
}
