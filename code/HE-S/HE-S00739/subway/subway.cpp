#include<bits/stdc++.h>
using namespace std;
int n,m,q,w[500001],k,a,b;
long long l[501][501];
vector<int>e[500001];
vector<long long>p[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&a,&n,&m,&b,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				l[i][j]=9999999999999999;
			}
		}
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&a,&b);
			e[a].push_back(i);
			p[a].push_back(b);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<e[i].size();j++){
			for(int k=0;k<j;k++){
				l[e[i][j]][e[i][k]]=min(l[e[i][j]][e[i][k]],p[i][j]+p[i][k]);
				l[e[i][k]][e[i][j]]=l[e[i][j]][e[i][k]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&j!=k&&k!=i){
					l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
				}
			}
		}
	}
	while(q--){
		long long ans=9999999999999999;
		scanf("%d%d",&a,&b);
		for(int i=0;i<e[a].size();i++){
			for(int j=0;j<e[b].size();j++){
				ans=min(ans,p[a][i]+p[b][j]+l[e[a][i]][e[b][j]]);
			}
		}
		ans+=w[a];
		ans+=w[b];
		printf("%lld\n",ans);
	}
	return 0;
}
