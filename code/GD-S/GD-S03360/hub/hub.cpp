#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,dep[1000005],f[1000005],t[1000005];
set<int>tr[1000005];
void dfs(int u,int fa,int &x){
	dep[u]=dep[fa]+1,f[u]=fa,t[u]=1;
	if(dep[u]>dep[x])x=u;
	for(auto v:tr[u]){
		if(v==fa)continue;
		dfs(v,u,x);
		t[u]=max(t[u],t[v]+1);
	}
}
int findrt(int u){
	int a=0;dfs(u,0,a);
	int b=0;dfs(a,0,b);
	int x=b;
	for(int i=1;i<=dep[b]/2;i++)x=f[x];
	return x;
}
int solve(int u,int v){
	u=findrt(u),v=findrt(v);
	priority_queue<pair<int,int>>q;
	int y=0,z=0;dfs(u,0,y);dfs(v,0,z);
	if(k==2)return max(t[u]-1,t[v]-1);
	for(auto x:tr[u])q.push({t[x],x});
	for(auto x:tr[v])q.push({t[x],x});
	for(int i=3;i<=k;i++){
		int u=q.top().second;q.pop();
		for(auto v:tr[u]){
			if(v==f[u])continue;
			q.push({t[v],v});
		}
	}
	if(q.size()==0)return 0;
	return q.top().first;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;int ans=1e18;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			tr[u].insert(v);
			tr[v].insert(u);
		}
		
		if(k==1){
			int rt=findrt(1),x=0;
			dfs(rt,0,x);
			cout<<dep[x]-1<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(auto x=tr[i].begin();x!=tr[i].end();){
				int u=*x;
				tr[u].erase(i);
				x=tr[i].erase(x);
				ans=min(ans,solve(u,i));
				tr[u].insert(i);
				tr[i].insert(u);
			}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
			tr[i].clear();
	}
	return 0;
}
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h>
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
//#include<bits\stdc++.h> 
