#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
const int INF=0x3f3f3f3f;
int cnt[N],n,m,vis[N],res[N];
vector<int>G[N];
void add(int x,int y){
	G[x].push_back(y);
	G[y].push_back(x);
}
void dfs2(int cur,int fa){
	for(auto u:G[cur]){
		if(!vis[u]&&res[u]){
			vis[u]=true;
			dfs2(u,cur);
		}
	}
}
int minn=INF,ans=INF;
void dfs3(int cur,int fa,int dist){
	if(res[cur]){
		minn=min(minn,dist);
		return;
	}
	for(auto u:G[cur]){
		if(u!=fa){
			dfs3(u,cur,dist+1);
		}
	}
}
void dfs(int cur,int num){
	if(cur==n+1){
		if(num!=m){
			return;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(res[i]&&!vis[i]){
				cnt++;
				vis[i]=true;
				dfs2(i,0);
			}
		}
		if(cnt>2){
			return;
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(!res[i]){
				minn=INF;
				dfs3(i,0,0);
				maxn=max(maxn,minn);
			}
		}
		ans=min(ans,maxn);
		return;
	}
	if(num<m){
		res[cur]=1;
		dfs(cur+1,num+1);
	}
	res[cur]=0;
	dfs(cur+1,num);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			res[i]=0;
			while(!G[i].empty()){
				G[i].pop_back();
			}
		}
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			add(x,y);
		}
		ans=INF;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}

