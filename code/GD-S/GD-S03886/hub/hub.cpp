#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1007;
int c,ans,t,n,k,dis[N][N],mi[N];
vector<int> v[N];
bool vis[N];

void clean(){
	memset(dis,0,sizeof(dis));
	memset(mi,0x3f,sizeof(mi));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) v[i].clear();
	ans=1e9+7;
}

void dfs(int st,int u,int fa){
	for(int i:v[u]){
		if(i==fa) continue;
		dis[st][i]=dis[st][u]+1;
		dfs(st,i,u);
	}
}

void cnt(int ti,int u){
	if(ti==0){
		memset(mi,0x3f,sizeof(mi));
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			for(int j=1;j<=n;j++){
				mi[j]=min(mi[j],dis[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			tot=max(tot,mi[i]);
		}
		ans=min(ans,tot);
		return;
	}
	if(k-ti>2){
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			for(int it:v[i]){
				if(vis[it]) continue;
				vis[it]=true;
				cnt(ti-1,it);
				vis[it]=false;
			}
		}
	}
	else {
		for(int i=u+1;i<=n;i++){
			vis[i]=true;
			cnt(ti-1,i);
			vis[i]=false;
		}
	}
}

void work(){
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
	}
	cnt(k,0);
	if(t==0) cout<<ans+1<<"\n";
	else cout<<ans<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		clean();
		work();
	}
	return 0;
}
