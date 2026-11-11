#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define int ll
#define inf 1e18
const int N=1e4+5;
int n,k;
vector<int>a[N];
int ans;
bool vis[N];
int fa[N];
vector<int>ch;
int dis[N][N];
int d[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void calc(){
	for(int i:ch){
		fa[i]=i;
	}
	for(int i:ch){
		for(int j:a[i]){
			if(vis[j]){
				int ii=find(i);
				int jj=find(j);
				if(ii!=jj){
					fa[ii]=jj;
				}
			}
		}
	}
	int cnt=0;
	for(int i:ch){
		if(i==find(i)){
			cnt++;
		}
	}
	if(cnt>2){
		return ;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			d[i]=0;
			continue;
		}
		d[i]=inf;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			d[i]=min(d[i],dis[i][j]);
		}
		res=max(res,d[i]);
	}
	ans=max(ans,res);
	return ;
}
void dfs(int nw,int s){
	if(nw==n+1&&s==k){
		calc();
		return ;
	}
	if(nw>n){
		return ;
	}
	if(s>k){
		return ;
	}
	vis[nw]=1;
	ch.push_back(nw);
	dfs(nw+1,s+1);
	vis[nw]=0;
	ch.pop_back();
	dfs(nw+1,s);
	return ;
}
void solve(){
	ch.clear();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=inf;
			}else{
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j:a[i]){
			dis[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ans=inf;
	dfs(1,0);
	cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

