#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const ll N=500,M=5e5,D=20,Q=1e5;
struct edge{
	ll v,w;
	operator <(edge x)const{
		return w>x.w;
	}
};
ll c,n,m,d,q,sw[M+10],f[M+N+10];
vector<edge>e[M+N+10];//way&sub
bitset<M+N+10>b,pg;//pg->รปล๖นý
inline void dj(ll u){
	priority_queue<edge>q;
	memset(f,0x7f,8*(m+n+5));
	b.reset();
	f[u]=0;
	q.push({u,0});
	for(ll u,w;!q.empty();){
		u=q.top().v;
		q.pop();
		if(!b[u]){
			b[u]=1;
			for(ll i=0,v,w;i<e[u].size();i++){
				v=e[u][i].v;w=e[u][i].w;
				if(f[v]>f[u]+w){
					f[v]=f[u]+w;
					if(!b[v]){
						q.push({v,w});
					}
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>sw[i];
	}
	for(ll i=1,k,v,w,lv;i<=n;i++){
		cin>>k>>lv>>w;
		e[lv].push_back({m+i,w});
		e[m+i].push_back({lv,w});
		for(ll j=2;j<=k;j++){
			cin>>v>>w;
			e[v].push_back({m+i,w});
			e[m+i].push_back({v,w});
		}
	}
	for(ll i=1,x,y;i<=q;i++){
		cin>>x>>y;
		dj(x);
		cout<<f[y]+sw[x]+sw[y]<<"\n";
	}
	return 0;
}
