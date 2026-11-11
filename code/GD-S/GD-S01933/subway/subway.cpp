#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct node{
	long long to,v;
};
vector<node>v[500005];
long long mp[505][505],w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			v[x].push_back({i,y});
		}
	}
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++)mp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				node x=v[i][j],y=v[i][k];
				mp[x.to][y.to]=mp[y.to][x.to]=min(mp[x.to][y.to],x.v+y.v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				mp[i][j]=mp[j][i]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				ans=min(ans,mp[v[x][j].to][v[y][k].to]+v[x][j].v+v[y][k].v);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
} 
