#include <bits/stdc++.h>
using namespace std;
struct node{
	long long to,wei;
	node(long long _to,long long _wei){
		to=_to;
		wei=_wei;
	}
};
long long e[514][514],c,n,m,d,q,ww[514114];
vector<node> G[514114];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>ww[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			e[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		e[i][i]=0;
	}
	for(int i=1,l;i<=n;++i){
		cin>>l;
		for(int j=1;j<=l;++j){
			long long a,w;
			cin>>a>>w;
			for(node nd:G[a]){
				long long v=nd.to,W=nd.wei;
				if(e[i][v-m]>W+w) e[i][v-m]=e[v-m][i]=W+w;
			}
			G[a].push_back(node(m+i,w));
			G[m+i].push_back(node(a,w));
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&j!=k&&i!=k) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--){
		long long ans=0x3f3f3f3f3f3f3f3f,x,y;
		cin>>x>>y;
		for(node X:G[x]){
			for(node Y:G[y]){
				ans=min(ans,X.wei+Y.wei+e[X.to-m][Y.to-m]);
			}
		}
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
}
