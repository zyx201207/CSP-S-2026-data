#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
inline ll read(){
	ll n=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return n*f;
}
const int N=1e6+5;
vector<int> g[N];
bool mk[N];
int n,k;
namespace A{
	int dep[N],pre[N];
	void bfs(vector<int> bg){
		for(int i=1;i<=n;i++) dep[i]=1e9;
		queue<int> q;
		for(auto x:bg) dep[x]=0,q.push(x);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(dep[v]==int(1e9)){
					q.push(v);
					dep[v]=dep[u]+1,pre[v]=u;
				}
			}
		}
		return;
	}
	void solve(){
		bfs({1});
		int p1=1;
		for(int i=1;i<=n;i++) if(dep[i]>dep[p1]) p1=i;
		bfs({p1});
		int p2=1;
		for(int i=1;i<=n;i++) if(dep[i]>dep[p2]) p2=i;
		vector<int> vec;
		for(int u=p2;u!=p1;u=pre[u]) vec.push_back(u);
		vec.push_back(p1);
		int len=int(vec.size())-1;
		int l=0,r=len/2;
		while(l<r){
			int mid=(l+r)>>1;
			bfs({vec[mid], vec[int(vec.size())-1-mid]});
			int mx=0;
			for(int i=1;i<=n;i++) mx=max(mx,dep[i]);
			if(mx<=mid) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
}
void solve(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) g[i].clear();
	vector<pii> E;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
		E.push_back({u,v});
	}
	if(n==k){
		puts("0");
		return;
	}
	if(n>10){
		A::solve();
		return;
	}
	int ans=1e9;
	for(int s=0;s<1<<n;s++){
		if(__builtin_popcount(s)!=k) continue;
		for(int i=0;i<n;i++) mk[i+1]=s>>i&1;
		int cnt=k;
		for(auto e:E){
			int u=e.fi,v=e.se;
			if(mk[u]&&mk[v]) cnt--;
		}
		if(cnt>2) continue;
		queue<int> q;
		static int dep[100];
		for(int i=1;i<=n;i++) dep[i]=1e9;
		for(int i=1;i<=n;i++) if(mk[i]) q.push(i),dep[i]=0;
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(auto v:g[u]){
				if(dep[v]==int(1e9)) q.push(v),dep[v]=dep[u]+1;
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,dep[i]);
		ans=min(ans,mx);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid=read(),T=read();
	while(T--){
		solve();
	}
	
	return 0;
}
