#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
#define N 2000010
int c,T;
int n,k;
vector<int>e[N];
int f[N];
int ans=INT_MAX;
int dis[N];
int bfs(int s){
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(f[u])return dis[u];
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[v]!=INT_MAX)continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
int check(){
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,bfs(i));
		cout<<f[i];
	}
	cout<<endl<<res<<endl;
	return res;
}
void got(int i,int nk){
	if(i>n){
		ans=min(ans,check());
		return;
	}
	if(nk)f[i]=1,got(i+1,nk-1);
	else f[i]=0,got(i+1,nk);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		ans=INT_MAX;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		got(1,k);
		cout<<ans<<endl;
	}
	return 0;
}

