#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{int to,nxt;}e[2000005];
int h[1000005],cnt=0;
void add(int x,int y){
	cnt++;
	e[cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
bool vis[1000005];
bool Vis[1000005];
void bfs(int s){
	queue<int>q;
	q.push(s);
	Vis[s]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=h[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(Vis[y]) continue;
			if(!vis[y]) continue;
			Vis[y]=1;
			q.push(y);
		}
	}
}
int ans=INT_MAX;
int d[1000005];
void check(){
	for(int i=1;i<=n;i++) Vis[i]=0;
	int st=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		if(Vis[i]) continue;
		st++;
		if(st>2) return ;
		bfs(i);
	}
//	cout<<st<<endl;
//	for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<' '; cout<<endl;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	for(int i=1;i<=n;i++){
		d[i]=INT_MAX;
		if(vis[i]) q.push({0,i}),d[i]=0;
	}
	while(!q.empty()){
		int x=q.top().second; q.pop();
		for(int i=h[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(d[y]>d[x]+1){
				d[y]=d[x]+1;
				q.push({d[y],y});
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,d[i]);
//	cout<<maxx<<endl;
//	if(maxx==1) cout<<INT_MAX<<' '<<INT_MAX<<endl;
	ans=min(ans,maxx);
}
void dfs(int x,int cnt){
	if(cnt>m) return ;
//	if(cnt+(n-x+1)<m) return ;
	if(x>n){
		if(cnt==m) check();
		return ;
	}
	if(cnt<m){
		vis[x]=1;
		dfs(x+1,cnt+1);
	}
	vis[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int CC; cin>>CC;
	int T; cin>>T;
	while(T--){
		ans=INT_MAX;
		cnt=0;
		memset(h,0,sizeof(h));
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y; cin>>x>>y;
			add(x,y); add(y,x);
		}
		dfs(1,0);
		cout<<ans<<endl;
//		cout<<endl<<endl<<endl<<endl;
	}
	return 0;
}

