#include<bits/stdc++.h>
#define int long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define C(i,j) ((m+1)*(i)+(j))
using namespace std;
int c,n,m,d,Q,W[500005],k,v,w,dis[30000005],x,y;
bool vis[30000005];
struct A{
	int v,w;
};
typedef pair<int,int> p;
vector<A>a[30000005];
void add(int u,int v,int w){
	a[u].push_back({v,w});
	a[v].push_back({u,w});
}
int di(int s,int t){
	for(int i=0;i<=(m+1)*(n+1);i++){
		dis[i]=4611686018427387903;
		vis[i]=0;
	}
	priority_queue<p,vector<p>,greater<p>>q;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(A i:a[u]){
			int w=dis[u]+i.w;
			if(w<dis[i.v]){
				dis[i.v]=w;
				q.push({w,i.v});
			}
		}
	}
	return dis[t]+W[s]+W[t];
}
signed main(){
	fre("subway");
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>v>>w;
			add(C(i,0),C(i,v),0);
			add(C(i,0),v,w);
		}
	}
	while(Q--){
		cin>>x>>y;
		cout<<di(x,y)<<endl;
	}
	return 0;
}

