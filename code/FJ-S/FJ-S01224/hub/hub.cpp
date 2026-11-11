#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f;
int c,tim,n,k,u,v,vis[N],dis[N],ans;
vector <int> vec[N];
void dfs (int msk,int x,int fa) {
	vis[x]=1;
	for(int i=0;i<(int)vec[x].size();i++) {
		int y=vec[x][i];
		if(y==fa) {
			continue;
		}
		if(vis[y]) {
			continue;
		}
		if(msk&(1<<(y-1))) {
			dfs(msk,y,x);
		}
	}
}
void work (int x,int fa,int dep) {
	dis[x]=min(dis[x],dep);
	for(int i=0;i<(int)vec[x].size();i++) {
		int y=vec[x][i];
		if(y==fa) {
			continue;
		}
		work(y,x,dep+1);
	}
}
void Sub1 () {
	ans=INF;
	for(int msk=1;msk<(1<<n);msk++) {
		int cnt=0;
		for(int i=0;i<n;i++) {
			dis[i+1]=INF;
			vis[i+1]=0;
			if(msk&(1<<i)) {
				cnt++;
			}
		}
		if(cnt!=k) {
			continue;
		}
		cnt=0;
		for(int i=0;i<n;i++) {
			if((msk&(1<<i))&&vis[i+1]==0) {
				dfs(msk,i+1,i+1);
				cnt++;
			}
		}
		if(cnt>2) {
			continue;
		}
		for(int i=0;i<n;i++) {
			if((msk&(1<<i))) {
				work(i+1,0,0);
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++) {
			mx=max(mx,dis[i]);
		} 
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tim;
	while(tim--) {
		cin>>n>>k;
		for(int i=1;i<=n;i++) {
			vec[i].clear();
		}
		for(int i=1;i<n;i++) {
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		Sub1();
		
	}
	return 0;
}
