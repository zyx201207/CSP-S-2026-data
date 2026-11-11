#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,ans=1e18,ss,tt;
const int N=5e5+7;
const int H=5005;
int w[N]={},t[H][H]={};
vector<int>k[N]={};
bool vis[H][H]={};
void dfs(int x,int u,int s,bool is){
	s+=t[x][u];
	vis[x][u]=1;
	if(s>ans)return;
	if(u==tt){
		ans=min(ans,s);
		return;
	}	
	for(int i=1;i<=n;i++){
		if(i==x)continue;
		if(t[i][u]!=0&&!vis[i][u])dfs(i,u,s,1);
	}if(is)
	for(int v:k[x]){
		if(!vis[x][v])dfs(x,v,s,0);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		while(s--){
			int v;
			cin>>v;
			cin>>t[i][v];
			k[i].push_back(v);
		}
	}
	while(q--){
		ans=1e18;
		memset(vis,0,sizeof(vis));
		cin>>ss>>tt;
		for(int i=1;i<=n;i++){
			if(t[i][ss]!=0)dfs(i,ss,0,1);			
		}
		cout<<w[ss]+w[tt]+ans<<endl;
	}
	return 0;
}
