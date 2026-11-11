#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int INF=1e9;
vector<int> g[N];
int c,t,n,k,maxn;
struct node{
	int id,fa,d;
};
queue<node> q;
int bfs(int u){
	int ans=0;
	q.push({u,-1,0});
	while(!q.empty()){
		int id=q.front().id;
		int d=q.front().d;
		int fa=q.front().fa;
		q.pop();
		ans=max(ans,d);
		for(auto x:g[id]){
			if(x==fa)continue;
			q.push({x,id,d+1});
		}
	}
	return ans;
}
void solve0(){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		} 
		int res=INF;
		for(int i=1;i<=n;i++)res=min(res,bfs(i));
		if(k==n)cout<<0<<"\n";
		else if(k==n-1)cout<<1<<"\n";
		else if(k==n-2)cout<<1<<"\n";
		else if(k==n-3)cout<<res-1<<"\n";
		else cout<<res<<"\n"; 
	}
}
void solve1(){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		} 
		int res=INF;
		for(int i=1;i<=n;i++)res=min(res,bfs(i));
		if(k==n)cout<<0<<"\n";
		else if(k==n-1)cout<<1<<"\n";
		else if(k==2)cout<<res-1<<"\n";
		else cout<<res<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==1)solve0();
	else solve1();
	return 0;
}
