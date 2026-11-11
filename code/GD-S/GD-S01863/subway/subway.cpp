#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
int n,m,d,q,c,w[510],st,ed,ans;
int a[510][2010],t[510][2010];
bool vis[500010];
vector<int>b[500010];
int mp[510][2010];
void dfs(int li,int u,int ti,int ed){
	if(u==ed){
		ans=min(ans,ti);
		return;
	}
	for(int i:b[u]){
		if(i==li)continue;
		int nt=ti+mp[i][u];
		for(int j=1;j<=a[i][0];j++){
			int v=a[i][j];
			if(!vis[v]){
				vis[v]=1;
				dfs(i,v,nt+t[i][j],ed);
				vis[v]=0;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].push_back(i);
			mp[i][a[i][j]]=t[i][j];
		}
	}
	while(q--){
		cin>>st>>ed;
		ans=(int)1e9;
		for(int i=1;i<=n;i++)vis[i]=0;
		vis[st]=1;
		dfs(0,st,w[st]+w[ed],ed);
		cout<<ans<<"\n";
	}
	return 0;
}

