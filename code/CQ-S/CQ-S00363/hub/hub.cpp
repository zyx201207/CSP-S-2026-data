#include<bits/stdc++.h>
using namespace std;
void fast(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
const int N=1e6+5;
int n,k;
map<int,map<int,bool>> d; 
int ans;
vector<int> e;
int fa[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool check(){
	for(int i:e){
		fa[i]=i;
	}
	int cnt=(int)e.size();
	for(int i=0;i<(int)e.size();i++){
		for(int j=i+1;j<(int)e.size();j++){
			int a=find(e[i]),b=find(e[j]);
			if(a!=b&&d[a][b]){
				cnt--;
				fa[a]=b;
			}
		}
	}
	return cnt<=2;
}
int f(){
	int res=0;
	bool vis[n+5]={0};
	queue<pair<int,int>> q;
	for(int i:e){
		q.push({i,0});
		vis[i]=1;
	}
	while(!q.empty()){
		int u=q.front().first;
		int dis=q.front().second;
		q.pop(); 
		res=max(res,dis);
		for(int i=1;i<=n;i++){
			if(!vis[i]&&d[u][i]){
				vis[i]=1;
				q.push({i,dis+1});
			}
		}
	}
	return res;
}
void dfs(int i){
	if((int)e.size()>k||(int)e.size()+n-i+1<k){
		return;
	}
	if(i==n+1){
		if((int)e.size()==k&&check()){
			ans=min(ans,f());
		}
		return;
	}
	dfs(i+1);
	e.push_back(i);
	dfs(i+1);
	e.pop_back();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fast();
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		d.clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			d[u][v]=d[v][u]=1;
		}
		ans=n;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}

