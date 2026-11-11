#include <bits/stdc++.h> 
using namespace std;
const int N=5e5+505;
using ll =long long;
const ll inf=1e18;
int c,n,m,dd,q;
ll w[N],d[N],T;
using pii=pair<int,ll>;
using iip=pair<ll,int>;
vector<pii> g[N] ;
struct Query{
	int u, v,id;
	ll ans;
}ql[N];
bool cmp(Query aa,Query bb){
	return aa.u<bb.u;
}bool cmp2(Query aa,Query bb){
	return aa.id<bb.id;
}
priority_queue<iip,vector<iip>,greater<iip> > pq;
queue<int> qq;
void clear(){
	while(qq.size())qq.pop();
	while(pq.size())pq.pop();
}
void bfs(int s) {
	qq.push(s);
	while(qq.size()){
		int x=qq.front();
		qq.pop();
		for(auto ps:g[x]){
			int v=ps.first;
			if(d[x]+1<d[v]){
				d[v]=d[x]+1;
				qq.push(v);
			}
		}
	}
}void dij(int s) {
	pq.push({0,s});
	while(pq.size()){
		auto xx=pq.top();
		int x=xx.second;
		ll ww=xx.first;
		pq.pop();
//		cerr<<x<<" "<<d[x]<<'\n';
		if(ww>d[x])continue;
		
		for(auto ps:g[x]){
			int v=ps.first;
			ll w=ps.second;
			if(d[x]+w<d[v]){
				d[v]=d[x]+w;
				pq.emplace(d[v],v);
			}
		}
	}
}
void init(int s){
	for(int i=1;i<=m+n;i++){
		d[i]=inf;
	}
	d[s]=0;
	clear();
	if(12<=c&&c<=19){
		bfs(s);
	}else{
		dij(s);
	}
//	cerr<<s<<":" ;
//	for(int i=1;i<=m+n;i++)cerr<<d[i]<<" ";
//	cerr<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	//ÏßÂ·µÄ£ºm+1~m+n; 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			cin>>x>>y;
			ll w=y;
			T=y;
			if(12<=c&&c<=19)w=1;
			g[x].emplace_back(m+i,w);
			g[m+i].emplace_back(x,w);
//			cerr<<x<<" "<<m+i<<" "<<w<<'\n';
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ql[i].u>>ql[i].v;
		if(ql[i].u>ql[i].v)swap(ql[i].u,ql[i].v) ;
		ql[i].id=i;
	}
	sort(ql+1,ql+1+q,cmp);
	int lst=0;
	for(int i=1;i<=q;i++){
		if(ql[i].u!=lst){
			init(ql[i].u);
		}
		lst=ql[i].u;
		ql[i].ans=d[ql[i].v]*T+w[ql[i].u]+w[ql[i].v];
	}
	sort(ql+1,ql+1+q,cmp2);
	for(int i=1;i<=q;i++)cout<<ql[i].ans<<'\n';
	return 0;
}
