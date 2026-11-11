#include<bits/stdc++.h>
using namespace std;
int bh,t,n,k,ans,dis[1000005];
vector<int> e[1000005];
bool v[1000005],vis[1000005];
queue<int> q;
void dfs1(int x){
	vis[x]=true;
	for(int i=0;i<e[x].size();i++){
		int j=e[x][i];
		if(!vis[j]&&v[j]) dfs1(j);
	}
}void dfs(int x,int la){
	if(x>k){
		for(int i=1;i<=n;i++) vis[i]=false;
		int cnt=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]||!v[i]) continue;
			if(++cnt>2) return; dfs1(i);
		}
		for(int i=1;i<=n;i++){
			if(!v[i]) dis[i]=n;
			else dis[i]=0,q.push(i); 
		}
		while(!q.empty()){
			int u=q.front(); q.pop();
			mx=max(mx,dis[u]);
			for(int i=0;i<e[u].size();i++){
				int j=e[u][i];
				if(dis[j]<=dis[u]+1) continue;
				dis[j]=dis[u]+1,q.push(j);
			}
		}ans=min(ans,mx); return;
	}
	for(int i=la+1;i<=n;i++){
		v[i]=true; dfs(x+1,i); v[i]=false;
	}
}void solve1(){
	dfs(1,0);
	cout<<ans<<'\n';
	return;
}
void solve2(){
	for(int x=1;x<n;x++){
		for(int y=x+1;y<=n;y++){
			int mx=0;
			for(int i=1;i<=n;i++) dis[i]=n;
			dis[x]=0,q.push(x);
			dis[y]=0,q.push(y);
			while(!q.empty()){
				int u=q.front(); q.pop();
				mx=max(mx,dis[u]);
				for(int i=0;i<e[u].size();i++){
					int j=e[u][i];
					if(dis[j]<=dis[u]+1) continue;
					dis[j]=dis[u]+1,q.push(j);
				}
			}ans=min(ans,mx);
		}
	}cout<<ans<<'\n'; return;
}
void solve3(){
	if(k==n){ cout<<"0\n"; return; }
	int m=(n+1)/2;
	if(k>m){ cout<<"1\n"; return; }
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)/2;
		int x=mid,y=m-mid;
		if(y-x+1<=k+2*mid-1) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n'; return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>bh>>t;
	while(t--){
		cin>>n>>k; ans=n;
		for(int i=1;i<=n;i++)
			e[i].clear(); 
		for(int i=1;i<n;i++){
			int x,y; cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(bh<=3) solve1();
		else if(bh==7) solve2();
		else if(bh==13||bh==14) solve3();
	}
	return 0;
}
