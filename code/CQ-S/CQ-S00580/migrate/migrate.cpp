#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int N=2e6+5;
int c,T;
ll n,d,a[N];
int ans=0,dis[N],cnt[N];
struct edge{
	int v,w;
};
vector<edge>g[N];
void add(int u,int v,int w){
	g[u].push_back({v,w});
}
struct node{
	int t,d;
};
bool operator < (const node& i,const node& j){
	return i.d>j.d;
}
priority_queue<node>pq;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		node p=pq.top();
		pq.pop();
		for(edge v:g[p.t]){
			if(v.v>=s&&p.d+v.w<dis[v.v]){
				dis[v.v]=p.d+v.w;
				pq.push({v.v,dis[v.v]});
			}
		}
	}
}
void get(int s){
	memset(cnt,0,sizeof(cnt));
	queue<node>q;
	q.push({s,0});
	cnt[s]=1;
	while(!q.empty()){
		node p=q.front();
		q.pop();
		for(edge v:g[p.t]){
			if(v.v>=s&&p.d+v.w==dis[v.v]) cnt[v.v]++,q.push({v.v,dis[v.v]});
		}
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
	for(int i=1;i<n;i++) add(i+1,i,0);
	for(int i=1;i<=n;i++){
		int l=i,r=n,maxn=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid]-a[i]<=d) maxn=max(maxn,mid),l=mid+1;
			else r=mid-1;
		}
		if(maxn!=i) add(i,maxn,1);
	}
	for(int i=1;i<=n;i++){
		dij(i);
		get(i);
		for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
