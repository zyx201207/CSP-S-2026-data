#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500005],p[100001][2];
struct Sub{
	int a1,t1,a2,t2;
}s[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		scanf("%d%d%d%d",&s[i].a1,&s[i].t1,&s[i].a2,&s[i].t2);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&p[i][0],&p[i][1]);
		int ans=w[p[i][0]]+w[p[i][1]]+s[1].t2;
		printf("%d\n",ans);
	}
	return 0;
}
