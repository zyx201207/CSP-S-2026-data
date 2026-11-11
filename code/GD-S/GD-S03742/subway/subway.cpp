#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct duilie{
	ll sum;
	int zd,xl;
};
struct dongtai{
	int lx,hc;
};
ll w[500005],a[505][500005],t[505][500005],h[505][500005];
vector<dongtai> v[505];
bool vis[500005];
ll bfs(ll x,ll y){
	queue<duilie> q;
	for(auto i:v[x]){
		q.push({i.hc,x,i.lx});
	}
	vis[x]=1;
	while(!q.empty()){
		auto top=q.front();
		ll d=top.sum;
		int u=top.zd;
		int now=top.xl;
		for(auto i:v[u]){
			if(now==i.lx){
				q.push({d,h[now][u],now});
			}
			else{
				q.push({})
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			h[i][a[i][j-1]]=a[i][j];
			v[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		ll s,z;
		cin>>s>>z;
		cout<<bfs(s,z)+w[s]+w[z]<<"\n";
	}
	return 0;
}
