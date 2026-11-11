#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int>w(500005),k(500005);
vector<vector<long long> >a(500005,vector<long long>(500005,1e18)),t(500005,vector<long long>(500005,1e18)),dis(500005,vector<long long>(500005,1e18));
void floyd(){
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int k=1;k<j;k++){
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],w[a[i][j]]+w[a[i][k]]+t[a[i][j]][a[i][k]]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	dis.resize(m+1,vector<long long>(m+1,1e18));
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	floyd();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld",dis[x][y]);
	}
	return 0;
}
