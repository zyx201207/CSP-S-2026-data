#include<bits/stdc++.h>
using namespace std;
int n,k,ans,num;
int fa[2000005];
bool bui[2000005],vis[2000005];
vector<int> g[2000005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	num--;
	fa[x]=y;
}
void dfs(int now,int last){
	if(now==n+1){
		if(last)return;
		num=k;
		for(int i=1;i<=n;i++)vis[i]=0,fa[i]=i;
		for(int i=1;i<=n;i++){
			for(auto v:g[i]){
				if(bui[i] && bui[v])merge(i,v);
			}
		}
		if(num>2)return;
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(bui[i])q.push(i),vis[i]=1;
		}
		int no=0;
		while(q.size()){
			int x=q.size();
			no++;
			for(int i=1;i<=x;i++){
				auto t=q.front();
				q.pop();
				for(auto v:g[t]){
					if(vis[v])continue;
					vis[v]=1;
					q.push(v);
				}
			} 
		}
		ans=min(ans,no-1);
		return;
	}
	bui[now]=0;
	dfs(now+1,last);
	if(last){
		bui[now]=1;
		dfs(now+1,last-1);
	}
	bui[now]=0;
} 
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//Never wanna give you up
	//Never gonna let you down
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=1e9+7;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,k);
		cout<<ans<<"\n";
	}
	return 0;
}
