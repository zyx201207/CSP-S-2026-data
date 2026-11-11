#include<bits/stdc++.h>
#define endl '\n'
#define lowbit(x) (x&-x)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=505,M=5e5+5,NM=M*21;
ll c,n,m,d,q,w[M],dis[NM],in[NM];
vector<pll>e[M*21];
inline void Add(int u,int v,ll w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
struct Line{
	ll k,id;
	void read(){
		ll aa,tt,paa=0;
		for(int i=1;i<=k;i++){
			cin>>aa>>tt;
			if(i!=1){
				Add(aa+id*m,paa+id*m,0);
			}
			paa=aa;
			Add(aa+id*m,aa,tt);
			in[aa+id*m]=tt;
		}
	}
}stat[N];
void dij(int st){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=20;i++)
		dis[st+i*m]=in[st+i*m];//,cout<<st+i*m<<"?"<<endl;
	priority_queue<pll,vector<pll>,greater<pll>>q;
	for(int i=1;i<=20;i++)
		q.push({dis[st+i*m],st+i*m});
	while(q.size()){
		auto t=q.top();q.pop();
		int u=t.second;
		//cout<<u<<"!?"<<endl;
		for(auto tt:e[u]){
			int v=tt.first,w=tt.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(in,0x3f,sizeof in);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>stat[i].k;
		stat[i].id=i;
		stat[i].read();
	}
	/*for(int i=1;i<=m*20;i++){
		cout<<i<<endl;
		for(auto t:e[i]){
			cout<<(t.first-1)+1<<' '<<t.second<<endl;
		}
	}*/
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		ll ans=0x3f3f3f3f3f3f3f3f;
		//cout<<"!"<<w[x];
		/*for(int i=1;i<=m;i++){
			cout<<dis[i]<<' ';
		}*/
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
