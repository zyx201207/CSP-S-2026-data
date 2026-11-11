#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 1e5 + 5,K = 1e5 + 5;
int c,n,m,d,q,w[M],b[N];
struct str{
	int k,a[N],t[N];
}v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;++i) scanf("%d",&w[i]);
	for(int i = 1;i <= n;++i){
		scanf("%d",&v[i].k);
		for(int j = 1;j <= v[i].k;++j) scanf("%d%d",&v[i].a[j],&v[i].t[j]); 
	}while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x == y){
			printf("0");
			continue;
		}int ans = w[x] + w[y],sum;
		memset(b,0,sizeof(b));
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= v[i].k;++j)
				if(v[i].a[j] == y) sum++,b[sum] = i;
		int minn = 1e9,ok = 0;
		for(int i = 1;i <= sum;++i)
			for(int j = 1;j <= v[i].k;++i)
				if(v[i].a[j] == x) ok = 1,minn = min(minn,v[i].t[x] + v[i].t[y]);
		if(ok){
			printf("%d\n",ans + minn);
			continue;
		}int minx = 1e9,miny = 1e9;
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= v[i].k;++j){
				if(v[i].a[j] == x) minx = min(minx,v[i].t[j]);
				if(v[i].a[j] == y) miny = min(miny,v[i].t[j]);
			}
		}printf("%d\n",ans + minx + miny);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
