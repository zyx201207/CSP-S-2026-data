#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x[100005],y[100005],k[500],w[500005];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%d",&w[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=0;i<q,i++){
		ans=w[x[i]]+w[y[i]];
		printf("%lld\n",(ans+a[i][w[a[i]]])*t[n][m]/c*(c-d)+ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
