#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
const ll M=5e5+5;
const ll K=305;
const ll F=1005;
const ll CCF=505;
ll id,n,m,d,q;
bool tsxz0=1;
struct edge{
	ll v,w;
};
vector<edge>e[F];
struct node{
	ll a,t;
};
vector<node>xl[CCF];
ll w[M],k[M],dis[K][K];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
//		duru.clear();
//		shijian.clear();
		for(ll j=1,x,y;j<=k[i];j++){
//			cin>>x;
//			duru[i].push_back(x);
//			cin>>x;
//			shijian[i].push_back(x);
			cin>>x>>y;
			xl[i].push_back(node{x+m,y});
		}
		if(k[i]!=2) tsxz0=0;
//		for(ll j=0;j<duru.size();j++){
//			for(ll k=j+1;k<duru.size();k++){
//				e[duru[j]+m+1].push_back(node{duru[k]+m+1,shijian[k]});
//				e[duru[k]+m+1].push_back(node{duru[j]+m+1,shijian[j]});
//			}
//			e[duru[j]+m+1].push_back(node{duru[j],shijian[j]});
//			e[duru[j]].push_back(node{duru[j]+m+1,shijian[j]});
//		}
	}
	if(tsxz0){
//		for(int i=1;i<=n;i++){
//			e[xl[i][0].a].push_back(node{xl[i][1].a,xl[i][0].t+xl[i][1].t});
//			e[xl[i][1].a].push_back(node{xl[i][0].a,xl[i][0].t+xl[i][1].t});
//		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) dis[i][j]=1e18;
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			dis[xl[i][0].a][xl[i][1].a]=min(dis[xl[i][0].a][xl[i][1].a],xl[i][0].t+xl[i][1].t);
			dis[xl[i][1].a][xl[i][0].a]=min(dis[xl[i][1].a][xl[i][0].a],xl[i][0].t+xl[i][1].t);
		}
		for(ll k=1;k<=m;k++){
			for(ll i=1;i<=m;i++){
				if(dis[i][k]==dis[0][0]) continue;
				for(ll j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<dis[l][r]+w[l]+w[r]<<endl;
		}
		return 0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<xl[i].size();j++){
			dis[i][xl[i][j].a]=xl[i][j].t+xl[i][i].t;
			dis[xl[i][j].a][i]=xl[i][j].t+xl[i][i].t;
		}
	}
	for(ll k=1;k<=2*m;k++){
		for(ll i=1;i<=2*m;i++){
			if(dis[i][k]==dis[0][0]) continue;
			for(ll j=1;j<=2*m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		cout<<dis[l][r]+w[l]+w[r]<<endl;
	}
	return 0;
} 
