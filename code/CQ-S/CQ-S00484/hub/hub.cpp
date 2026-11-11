#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,vis[1000005],f[1000005],k;
int dis[1000005],ans=1e9;
vector<int> vec[1000005];
int find(int x){
	return f[x]=x==f[x]?x:find(f[x]);
}
void dfs(int x,int cs){
	if(cs==k){
		for(int i=1;i<=n;i++) f[i]=i;int ltk=n;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j:vec[i]){
					if(vis[j]){
						int x=find(i),y=find(j);
						if(f[x]!=y) f[x]=y,ltk--;
					}
				}
			}
		}
//		cout<<"This zt:\nzh"<<'\n';
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<'\n';
//		cout<<ltk-(n-cs)<<'\n';
		if(ltk-(n-cs)>2) return ;
		for(int i=1;i<=n;i++) dis[i]=1e9;queue<int> que;
		for(int i=1;i<=n;i++) if(vis[i]) dis[i]=0,que.push(i);
		while(!que.empty()){
			int g=que.front();que.pop();
			for(int i:vec[g]){
				if(dis[i]==1e9){
					dis[i]=dis[g]+1;
					que.push(i);
				}
			}
		}int u=0;
//		cout<<"This zt:\nzh"<<'\n';
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<'\n';
//		for(int i=1;i<=n;i++) cout<<dis[i]<<' ';cout<<'\n'; 
		for(int i=1;i<=n;i++) u=max(u,dis[i]);
		ans=min(ans,u);
		return ;
	}
	if(x==n+1) return ;
	vis[x]=1;
	dfs(x+1,cs+1);
	vis[x]=0;
	dfs(x+1,cs);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=3){
		while(t--){
			ans=1e9;
			cin>>n>>k;for(int i=1;i<=n;i++) vec[i].clear();
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
				vec[u].push_back(v);
				vec[v].push_back(u);
			}dfs(1,0);cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
17:42

Ok啊也是比去年打的好啊，
100+100+24+15=239
239?真的能拿到一等吗？我问我自己、。

Maybe.因为去年T2和今年T2应该难度差不多，而去年只有217，今年肯定没有230啊 

我说白了谁搞的奇葩S组大赏？

我就直接灵感爆发了然后A了T2。 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/ 
