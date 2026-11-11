#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c,m,d,q,r1,r2,w[500005],f[100005];
vector<ll> e[100005];
void dijkstra(ll x){
	queue<ll> q;
	q.push(x);
	f[x]=2*w[x];
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(ll i:e[u]){
			int v=2*w[i];
			f[i]=min(f[i],v);
			q.push(i);
		}
		if(u==r2) return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			e[i].push_back(x);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r1>>r2;
		dijkstra(r1);
		cout<<f[r2]<<"\n";
	}
	return 0;
}
