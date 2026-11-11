#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int n,k;
vector <int> e[N];


int solve2(){
	int m=n/2;
	if(m<=k){
		return 1;
	}
	int lef=(m-k);
	if(lef&1){
		return (lef+1)/2+1;
	}else{
		return lef/2+1;
	}
}


int ans;
bool cho[N];

int bfs(){
	bool vis[12];	
	int dis[12];
	queue < pair <int,int> > q;
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=n+4;
	for(int i=1;i<=n;i++){
		if(cho[i]) q.push({i,0}),dis[i]=0;
	}
	while(!q.empty()){
		int u=q.front().first;
		if(vis[u]) continue;
		dis[u]=min(q.front().second,dis[u]);
		q.pop();
		vis[u]=1;
		for(auto v:e[u]){
			if(vis[v]) continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({v,dis[u]+1});
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,dis[i]);
	}
	return res;
}


int vvis[12];	
void ddfs(int u,int col){
	vvis[u]=col;
	for(auto v : e[u]){
		if(!cho[v]) continue;
		if(vvis[v]) continue;
		ddfs(v,col);
	}
	return ;
}

bool check4(){
	for(int i=1;i<=n;i++) vvis[i]=0;
	for(int i=1;i<=n;i++){
		if(cho[i]){
			ddfs(i,1);
			break;
		}	
	}
	for(int i=1;i<=n;i++){
		if(cho[i] && vvis[i]==0){
			ddfs(i,2);
			break;
		}	
	}
	for(int i=1;i<=n;i++){
		if(cho[i] && vvis[i]==0) return false;
	} 
	return true; 
}

void dfs(int x,int cnt){
	if(cnt>k) return;
	if(x==n+1){
		if(cnt!=k) return;
		if(!check4())return ;
		ans=min(ans,bfs());
		//if(ans==1){
		//	for(int i=1;i<=n;i++) cout<<cho[i]<<" ";
		//	exit(0);
		//}
		return ;
	}else{
		cho[x]=1;
		dfs(x+1,cnt+1);
		cho[x]=0;
		dfs(x+1,cnt);
	}
	return ;
}

void solve(){
	cin>>n>>k;
	ans=n+4;
	for(int i=1;i<=n;i++) e[i].clear(),cho[i]=0;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k==n){
		cout<<"0\n";
		return ;
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return ;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
