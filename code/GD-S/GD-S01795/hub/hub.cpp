#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=1e5+5;

int n,k;
vector<int> e[N];

struct sit1 {
	
	int tag[N];
	int fa[N];
	int vis[N];
	
	int find(int u) {
		return (u==fa[u]?u:fa[u]=find(fa[u]));
	}
	
	int calc(int S) {
		vector<int> arr;
		arr.clear();
		rep(u,1,n) tag[u]=0,fa[u]=u,vis[u]=0;
		rep(u,1,n) 
			if(S&(1<<(u-1)))
				arr.push_back(u),tag[u]=1;
		if((int)arr.size()!=k) return 1e9;
		rep(u,1,n) {
			if(!tag[u]) continue;
			for(auto v:e[u])
				if(tag[v] and find(u)!=find(v)) fa[find(u)]=find(v); 
		}
		int cnt=0;
		rep(u,1,n) 
			if(tag[u] and u==find(u)) cnt++;
		if(cnt>2) return 1e9;
		queue< pair<int,int> > q;
		while(!q.empty()) q.pop();
		for(auto u:arr) q.push(make_pair(u,0));
		int res=0;
		while(!q.empty()) {
			int u=q.front().first,d=q.front().second;
			q.pop();
			vis[u]=1;
			for(auto v:e[u]) {
				if(!vis[v]) {
					vis[v]=1;
					res=max(res,d+1);
					q.push({v,d+1});
				}
			}
		}
		return res;
	}
	
	void solve() {
		scanf("%d%d",&n,&k);
		rep(u,0,n) e[u].clear();
		rep(i,1,n-1) {
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v),e[v].push_back(u);
		}
		int ans=1e9;
		rep(S,1,(1<<n)-1) {
			ans=min(ans,calc(S));
		}
		printf("%d\n",ans);
		return ;
	}
	
	void _main() {
		int t;
		scanf("%d",&t);
		while(t--) solve();
		return ;
	}
	
}sol1;

struct sit2 {
	bitset<N> f;
	bitset<N> s[N];
	int vis[N];
	bool check(int x) {
		rep(i,1,n) s[i]=0,f[i]=1;
		queue< pair<int,int> > q;
		rep(st,1,n) {
			rep(p,1,n) vis[p]=0;
			while(!q.empty()) q.pop();
			q.push(make_pair(st,0));
			int res=0;
			while(!q.empty()) {
				int u=q.front().first,d=q.front().second;
				q.pop();
				vis[u]=1;
				if(d>x) continue;
				s[st][u]=1;
				for(auto v:e[u]) {
					if(!vis[v]) {
						vis[v]=1;
						res=max(res,d+1);
						q.push({v,d+1});
					}
				}
			}	
		}
		rep(u,1,n)
			rep(v,1,n)
				if((s[u]|s[v])==f) return 1;
		return 0;
	}
	void solve() {
		scanf("%d%d",&n,&k);
		rep(i,1,n) e[i].clear();
		rep(i,1,n-1) {
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int l=0,r=n,mid;
		while(l<r) {
			mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",r);
		return ;
	}
	void _main() {
		int t;
		scanf("%d",&t);
		while(t--) solve();
		return ;
	}
}sol2;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	scanf("%d",&c);
	if(c<=3) sol1._main();
	if(c==7) sol2._main();
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
