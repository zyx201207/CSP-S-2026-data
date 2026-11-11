#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct Node{
	int s,b[22];
}w[500050];
ll c,n,m,d,q,maxx,ans,p[500050];
void dfs(int s,int k){
	if(s>=k){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=0;i<w[s].s;i++){
		ans+=w[s].b[i];
		dfs(s+1,k);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>p[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			w[x].b[++w[j].s]=y;
		}
	}
	for(int i=1;i<=q;++i){
		int l,r;maxx=0,ans=0;
		cin>>l>>r;
		dfs(l,r);
		cout<<maxx+p[l]+p[r]<<endl;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+50;
int c,n,s,d,m,q,idx,a[N],t[N],p[N],h[N],w[N],e[N],nxt[N];
ll dis[N];
bool vis[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
void Addedge(int a,int b,int c){
	e[idx]=b;w[idx]=c;
	nxt[idx]=h[a];h[a]=++idx;
}
bool dijkstra(){
	memset(dis,0x3f,sizeof dis);
	pq.push({0,0});
	dis[0]=0;
	while(!pq.empty()){
		auto t=pq.top();pq.pop();
		//cout<<t.first<<" "<<t.second<<endl;
		if(vis[t.second])continue;
		vis[t.second]=1;
		for(int j=e[t.second];j!=-1;j=nxt[j]){
		//	cout<<j<<" ";
			if(dis[j]>dis[t.first]+w[j])dis[j]=dis[t.first]+w[j];
			pq.push({h[j],j});
			if(dis[j]>=n)return false;
		}
	}
	return true;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>p[i];
	for(int i=1;i<=n;++i){
		int x,y,z;
		cin>>x>>y>>z;
		Addedge(x,y,z);
		Addedge(y,x,z);
	}
	for(int i=0;i<=idx;i++)cout<<nxt[i]<<" "<<e[i]<<endl;
	if(dijkstra())return 0;
	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return 0;
}
*/
