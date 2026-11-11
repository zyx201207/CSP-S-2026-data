#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k,d[N],ans;
vector<int> e[N];
bool vis[N];
queue<pair<int,int>> q;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
int bfs(int root){
	if(q.size()) q.pop();
	q.push({root,0});
	while(q.size()){
		int u=q.front().first,now=q.front().second;q.pop();
		for(int v:e[u]){
			if(vis[v]) return now+1;
			else q.push({v,now+1});
		}
	}
	return 0;
}
void dfs(int u,int fa,int &diff){
	for(int v:e[u]){
		if(v==fa) continue;
		if(vis[u]!=vis[v]) diff++;
		dfs(v,u,diff);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();k=read();ans=N+10;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int mask=0;mask<(1<<n);mask++){
			int flag=0;
			for(int i=1;i<=n;i++) vis[i]=false,d[i]=0;
			for(int i=0;i<n;i++) if(mask&(1<<i)) flag++;
			if(flag!=k) continue;
			for(int i=0;i<n;i++) if(mask&(1<<i)) vis[i+1]=true;
			int diff=0;
			dfs(1,0,diff);
			if(diff>4) continue;
			for(int i=0;i<n;i++) if(!(mask&(1<<i))) d[i+1]=bfs(i+1);
			int res=0; 
			for(int i=1;i<=n;i++) res=max(res,d[i]);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

