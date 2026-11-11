#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> e[N];
int nn[N];
struct node{
	int x,fa;
};
int bfs(int x,int fa,int num){
	queue <node> q;
	nn[x]=num;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==fa){
			continue;
		}
		nn[x]--;
		if(nn[x]==0){
			return 1;
		}
		q.push({e[x][i],x});
	}
	node tmp=q.front();
	q.pop();
	return 1+bfs(tmp.x,tmp.fa,nn[tmp.fa]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; scanf("%d%d",&c,&t);
	while(t--){
		int n,k; scanf("%d%d",&n,&k);
		memset(nn,0,sizeof(nn));
	 	for(int i=1;i<n;i++){
	 		int u,v; cin>>u>>v;
	 		e[u].push_back(v);
	 		e[v].push_back(u);
	 	}
	 	int ans=INT_MAX;
	 	for(int i=1;i<=n;i++){
	 		if(e[i].size()==1){
	 			ans=min(ans,bfs(i,-1,k));
			 }
		 }
		 cout<<ans<<"\n";
	}
	return 0;
}

