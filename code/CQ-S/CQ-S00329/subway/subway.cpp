#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500100];
int a[510][500100];
vector<int> g[500100];
long long sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			int t;
			scanf("%d%lld",&a[i][j],&t);
			sum += t;
		}
	}
	for(int i = 1;i <= q;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		printf("%lld\n",sum + w[s] + w[e]);
	}
	return 0;
}
// Why can I only work out T1?
// I'm going to be AFO
// I don't know how to build up the graph.
// I have AKed CSP-J but I can only get 100 points in CSP-S.
// Goodbye,OI.
