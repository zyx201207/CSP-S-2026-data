//GZ-S00262 ³ÂÑô½õ 
#include<bits/stdc++.h>
#define  pii pair<int,int>
using namespace std;
const int N=500010,M=1000010;
vector<pii> g[M];
int dest[M],n,m,l[N];
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=m;i++) dest[i]=1e9;
	dest[s]=0;
	q.push({dest[s],s});
	while(q.size()){
		auto e=q.top();
		q.pop();
		int u=e.second;
	//	cout<<u<<' '<<dest[u]<<endl;
		for(auto d:g[u]){
			int v=d.second,w=d.first;
			if(dest[v]>=dest[u]+w){
				dest[v]=dest[u]+w;
				q.push({dest[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t,d,q;
	cin>>c>>t>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>l[i];
	m=n;
	for(int i=1;i<=t;i++){
		m++;
		int k,no,lo;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>no>>lo;
			g[m].push_back({lo,no});
			g[no].push_back({lo,m});
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		//cout<<"just"<<endl;
		dij(st);
		//cout<<"opp"<<endl;
		cout<<dest[en]+l[st]+l[en]<<endl;
	}
	return 0;
//	cin>>m>>n;
//	for(int i=1;i<=n;i++) {
//		int u,v,w;
//		cin>>u>>v>>w;
//		g[u].push_back({w,v});
//		g[v].push_back({w,u});
//	}
//	int s,e;
//	cin>>s>>e;
//	dij(s);
//	cout<<dest[e];
//	return 0;
}
