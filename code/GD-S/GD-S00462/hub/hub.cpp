#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,t;
int n,k;
vector<int>e[N];
vector<int>v;
int dep[N];
int f[20][N];
void dfs(int s,int fa){
	dep[s]=dep[fa]+1;
	for(int i=1;i<=25;i++){
		f[s][i]=f[f[s][i-1]][i-1];
	}
	for(auto t:e[s]){
		if(t==fa)continue;
		f[t][0]=s;
		dfs(t,s);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
		if(x==y)return y;
	}
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int ans=1e9,tmp=0;
int cnt[N];
int vis[N];
int len;
void work(){
	dfs(1,0);
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	for(int i=1;i<=rand()%90+10;i++){
		random_shuffle(v.begin(),v.end());
		len=0;
		for(int j=0;j<k;j++){
			vis[j]=1;
			for(int l=j+1;l<k;l++){
				int x=lca(v[j],v[l]);
				if(!cnt[x])len++;
			}
		}
		if(len>2)continue;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			int res=1e9;
			for(int l=0;l<k;l++){
				int x=lca(j,v[l]);
				if(x!=j)res=min(res,abs(dep[x]-dep[j]));
				if(x!=v[l])res=min(res,abs(dep[x]-dep[v[l]]));
				else res=min(res,abs(dep[x]-dep[j])+abs(dep[x]-dep[v[l]]));
//				cout<<res<<"\n";
			}
			tmp=max(tmp,res);
		}
		ans=min(ans,tmp);
		len=0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
	}
	cout<<ans<<"\n";
	ans=0;
	tmp=1e9;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		work();
		for(int i=1;i<=n;i++){
			e[i].clear();
			dep[i]=0;
		}
		memset(f,0,sizeof(f));
	}
	return 0;
}
