#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> ljb[501500];
long long c,n,m,d,q,w[500010],dist[501500];
struct zt{
	long long a,b;
};
struct xgd{
	vector<zt> a;
	long long size=0;
	zt top(){
		return a[1];
	}
	void pop(){
		a[1] = a[size];
		size--;
		long long dq=1;
		while(dq<=size/2){
			if(a[2*dq].b<a[dq].b){
				zt t=a[dq];
				a[dq] = a[2*dq];
				a[2*dq] = t;
				dq *= 2;
				continue;
			}
			if(a[2*dq+1].b<a[dq].b){
				zt t=a[dq];
				a[dq] = a[2*dq+1];
				a[2*dq+1] = t;
				dq = 2*dq+1;
				continue;
			}
			break;
		}
	}
	void push(zt x){
		if(a.size()==0){
			a.push_back({0,-1});
		}
		size++;
		if(a.size()>size){
			a[size] = x;
		}
		else{
			a.push_back(x);
		}
		long long dq=size;
		while(dq!=1){
			if(a[dq/2].b>a[dq].b){
				zt t=a[dq];
				a[dq] = a[dq/2];
				a[dq/2] = t;
				dq /= 2;
				continue;
			}
			break;
		}
	}
};
long long dijkstra(long long s,long long y){
	for(long long i=1;i<=m+n;i++){
		dist[i] = 0x3f3f3f3f3f3f3f3f;
	}
	xgd d;
	d.push({s,0});
	dist[s] = 0;
	while(!d.size==0){
		zt u=d.top();
		d.pop();
		if(u.b!=dist[u.a]){
			continue;
		}
		for(long long i=0;i<ljb[u.a].size();i++){
			long long nd=u.b+ljb[u.a][i].second;
			if(dist[ljb[u.a][i].first]>nd){
				dist[ljb[u.a][i].first] = nd;
				d.push({ljb[u.a][i].first,dist[ljb[u.a][i].first]});
			}
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		while(k--){
			long long a,t;
			scanf("%lld %lld",&a,&t);
			ljb[m+i].push_back({a,t});
			ljb[a].push_back({m+i,t});
		}
	}
	while(q--){
		long long x,y;
		cin >> x >> y;
		printf("%lld\n",w[x]+dijkstra(x,y)+w[y]);
	}
	return 0;
}
