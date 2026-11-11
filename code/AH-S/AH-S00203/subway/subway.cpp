#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l,a,b;
long long w[500005],t;
struct node{
	int id;
	long long x;
};
vector<node> v[500005]; 
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&l);
		for(int j=1;j<=l;j++){
			scanf("%d%lld",&a,&t);
			v[a].push_back((node){i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int sz=v[i].size();
		for(int j=0;j<sz-1;j++){
			for(int k=j+1;k<sz;k++){
				long long num=v[i][j].x+v[i][k].x;
				int d1=v[i][j].id,d2=v[i][k].id;
				f[d1][d2]=min(f[d1][d2],num);f[d2][d1]=min(f[d2][d1],num);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&a,&b);
		long long ans=1e18;
		int sz1=v[a].size(),sz2=v[b].size();
		for(int i=0;i<sz1;i++){
			for(int j=0;j<sz2;j++){
				int d1=v[a][i].id,d2=v[b][j].id;
				if(f[d1][d2]!=1e18) ans=min(ans,v[a][i].x+v[b][j].x+f[d1][d2]+w[a]+w[b]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
