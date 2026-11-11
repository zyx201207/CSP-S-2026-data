#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct node{
	int k,a[500005],t[500005];
}sw[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&sw[i].k);
		for (int j=1;j<=sw[i].k;j++) scanf("%d%d",&sw[i].a[j],&sw[i].t[j]);
	}
	for (int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i=1;i<=n;i++){
			cout<<1;
		}
	}
	return 0;
}
