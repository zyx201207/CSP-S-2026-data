#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<ll,int>;
const int maxn=5e5+1,maxm=501;
int n,m,d,q;
int w[maxn];
struct Line{
	int k,a[maxm];
	ll t[maxm];
}l[maxm];
ll dis[maxn];
vector<int> with[maxn];
ll query(int xr,int yr){
	priority_queue<pil,vector<pil>,greater<pil>> pq;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	pq.push({0,xr});
	dis[xr]=0;
	while(!pq.empty()){
		ll d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d>dis[u]){
			continue;
		}
		for(int i:with[u]){
			int k=l[i].k;
			ll nd=d;
			ll del=0;
			for(int j=1;j<=k;j++){
				if(l[i].a[j]==u){
					del=l[i].t[j];
				}
			}
			nd+=del;
			for(int j=1;j<=k;j++){
				int v=l[i].a[j];
				ll w=l[i].t[j];
				if(nd+w<=dis[v]){
					dis[v]=nd+w;
					pq.push({dis[v],v});
				}
			}
		}
	}
	return dis[yr]+w[xr]+w[yr];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int C;
	cin>>C>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		l[i].k=k;
		for(int j=1;j<=k;j++){
			cin>>l[i].a[j]>>l[i].t[j];
			with[l[i].a[j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		cout<<query(xr,yr)<<endl;
	}
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
