#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<ll,ll>
#define lg(x) (63-__builtin_clzll(x))
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll w[(int)5e5+100];
int c,n,m,d,q;
namespace subtask1{
	const int N=2e3+100;
	vector<pi> a[N];
	ll tot;
	ll dis[N][N];
	bool vis[N];
	void add(int u,int v,ll w){
		a[u].push_back({v,w});
	} 
	void dij(int st,ll dis[]){
		for(int i=1;i<=tot;i++) dis[i]=inf,vis[i]=false;
		priority_queue<pi,vector<pi>,greater<pi>> q;
		q.push({0,st});
		dis[st]=0;
		while(q.size()){
			int u=q.top().se;
			q.pop();
			if(vis[u]) continue;
			vis[u]=true;
			for(auto it:a[u])
				if(dis[it.fi]>dis[u]+it.se){
					dis[it.fi]=dis[u]+it.se;
					q.push({dis[it.fi],it.fi});
				}
		}
	}
	void main(){
		tot=m;
		for(int i=1;i<=n;i++){
			int k; cin>>k;
			for(int j=1;j<=k;j++){
				int id,c; cin>>id>>c;
				++tot;
				add(id,tot,c);
				add(tot,id,c);
				if(j>1) add(tot-1,tot,0);
			} 
		}
		for(int i=1;i<=tot;i++) dij(i,dis[i]);
		for(int i=1;i<=q;i++){
			int x,y; cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<"\n";
		}
	}
}
namespace subtask2{
	const int N=4e4+100;
	vector<pi> a[N];
	ll tot;
	ll dis[N];
	bool vis[N];
	void add(int u,int v,ll w){
		a[u].push_back({v,w});
	}
	void dij(int st,ll dis[]){
		for(int i=1;i<=tot;i++) dis[i]=inf,vis[i]=false;
		priority_queue<pi,vector<pi>,greater<pi>> q;
		q.push({0,st});
		dis[st]=0;
		while(q.size()){
			int u=q.top().se;
			q.pop();
			if(vis[u]) continue;
			vis[u]=true;
			for(auto it:a[u])
				if(dis[it.fi]>dis[u]+it.se){
					dis[it.fi]=dis[u]+it.se;
					q.push({dis[it.fi],it.fi});
				}
		}
	}
	void main(){
		tot=m;
		for(int i=1;i<=n;i++){
			int k; cin>>k;
			for(int j=1;j<=k;j++){
				int id,c; cin>>id>>c;
				++tot;
				add(id,tot,c);
				add(tot,id,c);
				if(j>1) add(tot-1,tot,0);
			} 
		}
		for(int i=1;i<=q;i++){
			int x,y; cin>>x>>y;
			dij(x,dis);
			cout<<w[x]+w[y]+dis[y]<<"\n";
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c<=11) subtask1::main();
	else if(c<=15) subtask2::main();
//	else subtask3::main();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
