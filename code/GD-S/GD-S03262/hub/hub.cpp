#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k;
vector<int> g[N];
int a[N],mark[N],vis[N],ans;
struct node{
	int a,b;
};
int dist(int st,int en){
	int cnt=1e9;
	int rt[N]={0};
	queue<node> q;
	rt[st]=1;
	q.push({st,0});
	while(!q.empty()){
		node p=q.front();
		q.pop();
		if(p.a==en){
			cnt=min(cnt,p.b);
			continue;
		}
		for(auto c:g[p.a]){
			if(!rt[c]){
				rt[c]=1;
				q.push({c,p.b+1}); 
			}
		}
	}
	return cnt;
}
void dfs(int now,int step){
	if(now==k+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			mark[i]=0;
		}
		for(int i=1;i<=n;i++){
			cnt++;
			if(cnt>2) break;
			queue<int> q;
			mark[i]=1;
			q.push(i);
			while(!q.empty()){
				int p=q.front();
				vis[p]=0;
				q.pop();
				for(auto c:g[p]){
					if(!mark[c]){
						mark[c]=1;
						q.push(c);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) return ;
		}
		int tmp=0;
		for(int i=1;i<=n;i++){
			int d=1e9;
			for(int j=1;j<=k;j++){
				d=min(d,dist(i,a[j]));
			}
			tmp=max(tmp,d);
		}
		ans=min(ans,tmp);
		return ;
	}
	for(int i=step;i<=n;i++){
		a[k]=i;
		vis[i]=1;
		dfs(now+1,i+1);
		vis[i]=0;
	}
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	dfs(1,1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
