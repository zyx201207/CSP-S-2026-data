#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int N=5e5+1005;
const int M=5e6+5;
const int Q=1e5+5;
int c,n,m,d,q,dis[N],diss[N],w[N],ans[Q];
vector<pair<int,int> > e[N];//v,w
struct st{
	int x,y,id;
}s[Q];
bool cmp(st a,st b){
	return a.x<b.x;
}
void dijkstra(int start){
	memset(dis,0x3f,sizeof(dis));
	memset(diss,0,sizeof(diss));
	priority_queue<pair<int,int> > q;
	//-×Üw,p
	dis[start]=0;
	q.push({0,start});
	while(q.size()){
		auto t=q.top();q.pop();
		if(diss[t.S])continue;diss[t.S]=1;
		for(auto v:e[t.S]){
			if(dis[t.S]+v.S<dis[v.F]){
				dis[v.F]=dis[t.S]+v.S;
				q.push({-dis[v.F],v.F});
			}
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,t;i<=m;i++){
//		cin>>t;
		cin>>w[i];
	}
	for(int i=1,k,p,v;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>p>>v;
			e[m+i].push_back({p,v});
			e[p].push_back({m+i,v});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i].x>>s[i].y;
		s[i].id=i;
		if(s[i].x>s[i].y)swap(s[i].x,s[i].y);
	}
	sort(s+1,s+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(s[i].x!=s[i-1].x)
			dijkstra(s[i].x);
		ans[s[i].id]=w[s[i].x]+w[s[i].y]+dis[s[i].y];
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
/*
n*n log n
*/ 
