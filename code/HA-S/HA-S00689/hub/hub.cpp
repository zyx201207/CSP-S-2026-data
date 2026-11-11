#include<bits/stdc++.h>

using namespace std;
#define maxn 1000006
int c,t,n,k;
vector<int> e[maxn];
bool vis[maxn];
int siz[maxn],maxs[maxn],son[maxn],rot;
void getr(int i,int f) {
	siz[i] = 1,maxs[i]=-1;
	for(auto j:e[i]) {
		if(j==f||j==rot) continue;
		getr(j,i);
		siz[i]+=siz[j];
		if(maxs[i]<siz[j])
			maxs[i]=max(maxs[i],siz[j]),son[i]=j;
	}
	maxs[i]=max(maxs[i],n-siz[i]);
	if(maxs[i]<maxs[rot]) rot=i;
}

int dis[maxn],mdis[maxn];
void trt(int &l,int &r) {

	if(siz[l]<siz[r]) swap(l,r);
	int lst=min(min(maxs[l],maxs[r]),n-siz[l]-siz[r]);
	while(min(min(maxs[son[l]],maxs[r]),n-siz[son[l]]-siz[r])<lst) {
		l=son[l];
		if(siz[l]<siz[r]) swap(l,r);
	}
}
void dfs1(int i,int f,int d) {
	dis[i] = d;
	for(auto j:e[i]) {
		if(j==f)continue;
		dfs1(j,i,d+1);
		dis[i]=max(dis[i],dis[j]);
	}
}
void dfs2(int i,int f) {
	mdis[i] = dis[i];
	for(auto j:e[i]) {
		if(j==f)continue;
		if(dis[j]<dis[i]) continue;
		dfs2(j,i);
		mdis[i]=max(mdis[i],dis[j]);
	}
}
void bfs(int l,int r) {
	queue<pair<int,int> >q;
	q.push({1,l}),q.push({1,r});
	while(!q.empty()) {
		int k=q.front().first,i=q.front().second;
		q.pop();
		if(dis[i]) continue;
		dis[i] = k;
		for(auto j:e[i])
			q.push({k+1,j});
	}
}

priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > pq;

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		vis[1] = 0,dis[1]=mdis[1]=0;
		cin>>n>>k;
		for(int i=1,u,v; i<n; i++) {
			cin>>u>>v;
			vis[i+1]=dis[i+1]=mdis[i+1]=0;
			e[u].push_back(v),e[v].push_back(u);
		}
		maxs[rot=0]=998244353;
		getr(1,0);
		getr(rot,rot);
		if(k==n){
			cout<<"0\n";
		}
		if(k==1) {
			dfs1(rot,rot,0);
			cout<<dis[rot]<<'\n';
		} else {
			k -= 2;
			int l=son[rot],r=0;
			for(auto j:e[rot]) {
				if(j!=son[rot]&&siz[j]>siz[r]) r=j;
			}
			trt(l,r);
			bfs(l,r);
			dfs2(l,l);
			dfs2(r,r);
			vis[l]=vis[r] = 1;
			for(auto j:e[l]) {
				if(vis[j]) continue;
				vis[j] = 1;
//					cerr<<"E"<<j<<' '<<mdis[j]<<'\n';
				pq.push({mdis[j],j});
			}
			for(auto j:e[r]) {
				if(vis[j]) continue;
				vis[j] = 1;
//					cerr<<"E"<<j<<' '<<mdis[j]<<'\n';
				pq.push({mdis[j],j});
			}
			while(!pq.empty()&&k) {
				int i=pq.top().second,val=pq.top().first;
				pq.pop(),k--,vis[i] = 1;
				for(auto j:e[i]) {
					if(vis[j]) continue;
//					cerr<<k<<"E"<<j<<' '<<mdis[j]-dis[j]+1<<'\n';
					pq.push({mdis[j]-dis[j]+1,j});//min(mdis[j],val-1)
				};
			}
			ans = pq.top().first;
			while(!pq.empty()) {
//				cerr<<pq.top().first<<' ';
				pq.pop();
			}
			cout<<max(1,ans-1)<<'\n';


		}

		for(int i=1; i<=n; i++) e[i].clear();
	}

	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

