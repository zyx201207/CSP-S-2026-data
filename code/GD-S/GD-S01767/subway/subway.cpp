#include<bits/stdc++.h>
#define psb push_back
#define ll long long
using namespace std;
const ll M=5e5+5,N=500+5;
const ll inf=1e17;
ll C,n,m,D,Q;
ll w[M],dis[505][505];
struct Node{
	ll id,val;
};
vector<Node> b[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>D>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll idd=1,k;idd<=n;idd++){
		cin>>k;
		for(ll i=1,b1,v1;i<=k;i++){
			cin>>b1>>v1;
			b[b1].psb({idd,v1});
		}
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=inf;
		}
	}
	for(ll i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		if(b[i].size()<=1) continue;
		for(ll j=0;j<(ll)b[i].size();j++){
			for(ll k=j+1;k<(ll)b[i].size();k++){
				ll id1=b[i][j].id,id2=b[i][k].id;
				ll v1=b[i][j].val,v2=b[i][k].val;
				ll cur=v1+v2;
				dis[id1][id2]=min(dis[id1][id2],cur);
				dis[id2][id1]=min(dis[id2][id1],cur);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll o=1,u,v,res;o<=Q;o++){
		cin>>u>>v;
		res=inf;
		for(ll i=0;i<(ll)b[u].size();i++){
			for(ll j=0;j<(ll)b[v].size();j++){
				ll id1=b[u][i].id,id2=b[v][j].id;
				ll v1=b[u][i].val,v2=b[v][j].val;
				res=min(res,v1+dis[id1][id2]+v2);
			}
		}
		res=res+w[u]+w[v];
		cout<<res<<"\n";
	}
	return 0;
}
