#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int N=1e6+10;
int fa[N],vis[N],dis[N];
int T,c,n,ans,k;
vector<int> t[N];
unordered_map<int,int> ma;
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		vis[i]=0;
	}
}
int find_f(int x){
	return x==fa[x]?x:fa[x]=find_f(fa[x]);
}
int Merge(int x,int y){
	x=find_f(x);
	y=find_f(y);
	if(x!=y){
		fa[x]=y;
		return 1;
	} 
	return 0;
}
int solve(int S){
	init();
	int ans=0,siz=0;
	for(int i=0;i<n;i++){
		if((S>>i)&1){
			vis[i+1]=1;
			dis[i+1]=0;
			siz++;
		}
		else{
			dis[i+1]=114514;
		}
	}
	if(siz!=k) return 1919810;
	queue<int> q; 
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		q.push(i);
		for(int j=0;j<t[i].size();j++){
			if(vis[t[i][j]]){
				siz-=Merge(i,t[i][j]);
			}
		}
	}
	if(siz>2) return 114514;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<t[u].size();j++){
			int v=t[u][j];
			dis[v]=min(dis[v],dis[u]+1);
			ans=max(ans,dis[v]);
			if(!vis[v]){
				q.push(v);
				vis[v]=1;
			} 
		}
	}
	return ans;
}
int main(){
	FILE("hub"); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=114514;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		for(int S=1;S<(1<<n);S++){
			ans=min(ans,solve(S));
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
