#include <bits/stdc++.h>
using namespace std;
const long long M=5e5+10;
const long long N=510;
long long c,n,m,d,T;
long long w[M],vis[N],dis[N];
long long head[M],to[M],nxt[M],cnt,val[M];
void add(long long x,long long y,long long z){
	nxt[cnt]=head[x];
	to[cnt]=y;
	val[cnt]=z;
	head[x]=cnt++;
}
struct node{
	long long x,v;
	bool operator<(const node & other)const{
		return other.v<v;
	}
};
priority_queue<node> q;
void Dij(long long s){
	for(int i=1;i<=m;i=i+1) dis[i]=1e9;
	for(int i=1;i<=m;i=i+1) vis[i]=0;
	q.push({s,0});dis[s]=0;
	while(!q.empty()){
		while(vis[q.top().x]==1&&!q.empty()){
			q.pop();
			if(q.empty()) break;
		}
		if(q.empty()) break;
		node now=q.top();q.pop();
		if(vis[now.x]==1) continue;
		vis[now.x]=1;
		for(int i=head[now.x];~i;i=nxt[i]){
			if(dis[to[i]]>dis[now.x]+val[i]){
				dis[to[i]]=dis[now.x]+val[i];
				q.push({to[i],dis[to[i]]});
			}
		}
	}
}
void solve(){
	long long s,t;
	cin>>s>>t;
	Dij(s);
	cout<<w[s]+w[t]+dis[t]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i=i+1) cin>>w[i];
	for(int i=1;i<=n;i=i+1){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j=j+1){
			long long a,t;
			cin>>a>>t;
			add(i,a,t);
			add(a,i,t);
		}
	}
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
