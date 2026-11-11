#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,Q=1e5+1;
struct node{
	int x,y,i;
}r[Q];
int c,n,m,d,q;
long long dp[M*21],w[M],da[Q],v[M];
vector<pair<int,long long> >adj[M*21+1];
bool cmp(node a,node b){
	return a.x<b.x;
}
int zb(int a,int i){
	return (a-1)*21+i;
}
void dij(int x){
	priority_queue<pair<long long,int> >q;
	bool b[M];
	memset(b,0,sizeof b);
	q.push({0,x});
	dp[x]=0;
	b[x]=1;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto c:adj[u]){
			int v=c.first;
			long long w=c.second;
			if(dp[v]>dp[u]+w){
				dp[v]=dp[u]+w;
				if(!b[v]){
					q.push({dp[v],v});
					b[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t,ab;
		cin>>k>>a>>t;
		v[a]++;
		adj[zb(a,v[a])].push_back({zb(a,0),t});
		adj[zb(a,0)].push_back({zb(a,v[a]),t});
		ab=a;
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			v[a]++;
			adj[zb(a,v[a])].push_back({zb(a,0),t});
			adj[zb(a,0)].push_back({zb(a,v[a]),t});
			adj[zb(a,v[a])].push_back({zb(ab,v[ab]),0});
			adj[zb(ab,v[ab])].push_back({zb(a,v[a]),0});
			ab=a;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
		r[i].i=i;
	}
	sort(r+1,r+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(r[i].x!=r[i-1].x){
			memset(dp,0x3f3f3f3f,sizeof dp);
			dij(zb(r[i].x,0));
		}
		da[r[i].i]=dp[zb(r[i].y,0)]+w[r[i].x]+w[r[i].y];
	}
	for(int i=1;i<=q;i++)
		cout<<da[i]<<"\n";
	return 0;
}
