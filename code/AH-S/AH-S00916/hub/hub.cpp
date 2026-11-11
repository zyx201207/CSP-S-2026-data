#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int> g[1000005];
bool vis1[1000005];
bool vis2[1000005];
bool vis3[1000005];
bool vis4[1000005];
struct node{
	int now,dis;
};
int js(int u){
	int minn=INT_MAX;
	memset(vis2,0,sizeof vis2);
	vis2[u]=1;
	vis4[u]=1;
	queue<node> q;
	q.push({u,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		int len=g[u.now].size();
		if(vis1[u.now]==1&&vis4[u.now]==0){
			minn=min(minn,u.dis);
			vis4[u.now]=1;
		}
		for(int i=0;i<len;i++){
			int next=g[u.now][i];
			if(vis2[next]==1)continue;
			q.push({next,u.dis+1});
			vis2[next]=1;
		}
	}
	return minn;
}
void found(int x){
	vis3[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int len=g[u].size();
		for(int i=0;i<len;i++){
			if(vis3[g[u][i]]==1)continue;
			q.push(g[u][i]);
			vis3[g[u][i]]=1;
		}
	}
}
bool lt(){
	int cnt=0;
	memset(vis3,0,sizeof vis3);
	for(int i=1;i<=n;i++){
		if(vis1[i]==1&&vis3[i]==0){
			found(i);
			cnt++;
		}
	}
	if(cnt<=2)return true;
	else return false;
}
void dfs(int st,int deep){
	if(deep==k&&lt()){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(vis1[i]==0){
				memset(vis4,0,sizeof vis4);
				maxn=max(maxn,js(i));
			}
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=st;i<=n;i++){
		if(vis1[i]==0){
			vis1[i]=1;
			dfs(i+1,deep+1);
			vis1[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		memset(vis1,0,sizeof vis1);
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

