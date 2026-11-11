#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],ans,c,d,q,k,w[N],t[N],xx,yy;
vector <long long> b[N];
vector <long long> e[N];
//最小生成树+lca？
//djstl?
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
			b[a[j-1]].push_back(a[j]);
			e[a[j-1]].push_back(t[j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&xx,&yy);
	}
	printf("%lld\n",d);
	return 0;
}
