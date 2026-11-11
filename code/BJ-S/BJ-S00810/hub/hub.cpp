#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
int n,k,c,t;
int vis[MAXN],vis2[MAXN];
vector<int>Graph[MAXN];
int solve(){
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			vis2[i]=1;
			q.push(make_pair(i,0));
		}
	}	
	int ans=0;
	while(!q.empty()){
		int id=q.front().first,st=q.front().second;
		//cout<<id<<" "<<st<<endl;
		ans=max(ans,st);
		q.pop();
		for(unsigned int i=0;i<Graph[id].size();i++){
			int v=Graph[id][i];
			if(vis2[v])continue;
			vis2[v]=1;
			q.push({v,st+1});
		}
	}
	memset(vis2,0,sizeof(vis2));
	//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
	//cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			q.push(make_pair(i,0));
		}
	}
	int block_num=0;
	while(!q.empty()){
		int id=q.front().first;
		if(!vis2[id])block_num++;
		vis2[id]=1;
		q.pop();
		for(unsigned int i=0;i<Graph[id].size();i++){
			int v=Graph[id][i];
			if(vis2[v]||!vis[v])continue;
			vis2[v]=1;
			q.push({v,0});
		}
		
	}
	memset(vis2,0,sizeof(vis2));
	if(block_num>2)return INT_MAX;
	return ans;
}
int dfs(int id,int num){
	if(id==n+1&&num==k)return solve();
	if(id==n+1)return INT_MAX;
	vis[id]=1;
	int ans=INT_MAX;
	if(num!=k)ans=min(ans,dfs(id+1,num+1));
	vis[id]=0;
	ans=min(ans,dfs(id+1,num));
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)Graph[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			Graph[u].push_back(v);
			Graph[v].push_back(u);
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		if(c==13||c==14){
			int tmp=(n-1)/2;
			if(k>=tmp){
				cout<<1<<endl;
				continue;
			}
			cout<<ceil((tmp-k)*1.0/3.0)+2<<endl;
		}
		else cout<<dfs(1,0)<<endl;
	}
	return 0;
}
//n^3+nk+d^2q
