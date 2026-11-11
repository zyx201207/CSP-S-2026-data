#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,ans,dis[1005][1005];
vector<int>v[1005],xuan;
bool vis[1005],book[1005];
queue<int>q;
bool check(){
	for(int i=1;i<=n;++i)vis[i]=false;
	int tot=0;
	for(auto i:xuan){
		if(!vis[i]){
			++tot;
			if(tot>=3)return false;
			while(!q.empty())q.pop();
			vis[i]=true,q.emplace(i);
			while(!q.empty()){
				int p=q.front();
				q.pop();
				for(auto j:v[p])if(book[j]&&!vis[j])vis[j]=true,q.emplace(j);
			}
		}
	}
	return true;
}
void dfs(int now,int las){
	if(now==k+1){
		int ans1=0;
		for(int i=1;i<=n;++i){
			int cnt=1e9;
			for(auto j:xuan)cnt=min(cnt,dis[i][j]);
			if(cnt>=ans)return;
			ans1=max(ans1,cnt);
		}
		if(ans1<ans)if(check())ans=ans1;
		return;
	}
	for(int i=las+1;i<=n;++i){
		book[i]=true,xuan.emplace_back(i),dfs(now+1,i),xuan.pop_back(),book[i]=false;
	}
	return;
}
void test(){
	cin>>n>>k,ans=1e9,xuan.clear();
	for(int i=1;i<=n;++i)v[i].clear(),book[i]=false; 
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y,v[x].emplace_back(y),v[y].emplace_back(x);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)vis[j]=false,dis[i][j]=0;
		vis[i]=true;
		while(!q.empty())q.pop();
		q.emplace(i);
		while(!q.empty()){
			int p=q.front();
			q.pop();
			for(auto j:v[p]){
				if(vis[j])continue;
				vis[j]=true,dis[i][j]=dis[i][p]+1,q.emplace(j);
			}
		}
	}
	dfs(1,0),cout<<ans<<"\n";
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)test();
	return 0;
}
