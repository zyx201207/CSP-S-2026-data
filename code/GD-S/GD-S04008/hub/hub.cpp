#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int C,T,n,k;
vector<int>h[N];
int a[N],dis[N],ans;
queue<int>q;
bool vis[N];
void Dfs(int u){
	vis[u]=0;
	for(int v:h[u])if(vis[v])Dfs(v);
	return;
}
void dfs(int u,int lst){
	if(u==k){
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)dis[i]=-1,vis[i]=0;
		for(int i=1;i<=k;i++)
			vis[a[i]]=1,
			dis[a[i]]=0,
			q.push(a[i]);
		int sum=0;
		for(int i=1;i<=k;i++)if(vis[a[i]]){
			sum++;
			Dfs(a[i]);
		}
		if(sum>2)return;
		int maxn=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			maxn=max(maxn,dis[u]);
			for(int v:h[u])if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=lst;i<=n-k+u+1;i++){
		a[u+1]=i;
		dfs(u+1,i+1);
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)h[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			h[u].push_back(v);
			h[v].push_back(u);
		}
		ans=2147483647;
		dfs(0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
