#include<bits/stdc++.h>
using namespace std;
const long long N=5005; 
long long c,n,m,d,q,w[505],k,t[N][505],x,y,a[N][505],dis[N][N];
struct road{
	long long to,id;
};
vector <road> v[N];
struct node{
	long long pos,d,ha;
};
void solve(long long fx){
	queue <node> pq;
	for(long long i=2;i<=m;i++){
		dis[fx][i]=1e18;
	}
	for(int i=1;i<=n;i++){
		if(t[fx][i]!=0){
			pq.push({fx,t[fx][i]+w[fx],i});
		}
	}
	while(!pq.empty()){
		node h=pq.front();
		pq.pop();
		for(auto e:v[h.pos]){
			if(e.id==h.ha){
				pq.push({e.to,h.d,h.ha});
				dis[fx][e.to]=min(dis[fx][e.to],h.d+t[e.to][e.id]+w[e.to]);
			}else if(e.id!=h.ha){
				dis[fx][e.to]=min(dis[fx][e.to],h.d+t[h.pos][h.ha]+t[h.pos][e.id]+t[e.to][e.id]+w[e.to]);
				pq.push({e.to,h.d+t[h.pos][h.ha]+t[h.pos][e.id],e.id});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		cin>>a[1][i];
		cin>>t[a[1][i]][i];
		for(int l=2;l<=k;l++){
			cin>>a[l][i];
			cin>>t[a[l][i]][i];
			v[a[l-1][i]].push_back({a[l][i],i});
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		if(dis[x][y]!=0){
			cout<<dis[x][y]<<'\n';
		}else{
			solve(x);
			cout<<dis[x][y]<<'\n';
		}
	}
	return 0;
}
