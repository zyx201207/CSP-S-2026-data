#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n,k;

vector<int> g[N];

int vis[N];
int ans;

bool vis2[N];
void mark(int x,int pre){
	vis2[x]=1;
	for(int i:g[x]){
		if(vis[i] && i!=pre)
			mark(i,x);
	}
}
bool check(){
	memset(vis2,0,sizeof(vis2));
	int tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i] && !vis2[i]){
			tot++;
			if(tot>2) return 0;
			mark(i,i);
		}
	}
	return 1;
}

int close(int x,int pre,int dep=0){
	if(vis[x]) return dep;
	int anss=INT_MAX;
	for(int i:g[x]){
		if(i!=pre)
			anss=min(anss,close(i,x,dep+1));
	}
	return anss;
}

void upd(){
	int ans2=0;
	for(int i=1;i<=n;i++){
		ans2=max(ans2,close(i,i,0));
	}
	ans=min(ans,ans2);
}

void solve(){
	for(int i=1;i<=n;i++)
		g[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=k;i++)
		vis[i]=1;
	ans=INT_MAX;
	sort(vis+1,vis+n+1);
	do{
		if(check()){
			upd();
		}
	}while(next_permutation(vis+1,vis+n+1));
	cout<<ans<<'\n';
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}