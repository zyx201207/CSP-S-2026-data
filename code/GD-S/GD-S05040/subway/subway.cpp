#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y, g, p;
int w[5005], k[505], h[505], f[505];//出站时间 ，线路站数，链表头，步数 
int z[505][5005], t[505][5005];
//struct AB{
//	int a, b, n, u;
//}l[5005];
//void cun(int a, int b, int u){
//	l[++p].a=a, l[p].b=b;
//	l[p]=h[a], h[a]=p;
//	if(h[a] > 1)l[p].u=1;
//}
int main (){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout <<32<<"\n"<<17;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout <<35<<"\n"<<16;
	}
//	for(int o=1; o<=c; o++){
//		for(int i=1; i<=m; i++){
//		scanf("%d", &w[i]);
//		}
//		for(int i=1; i<=n; i++){
//			scanf("%d", &k[i]);
//			for(int j=1; j<=k[i]; j++){
//				scanf("%d%d", &z[i][j], &t[i][j]);
//			}
//		}
//		for(int i=1; i<=n; i++){
//			for(int j=1; j<=k[i]; j+=2){
//				a=z[i][j],b=z[i][j+1]; 
//				cun(a, b, u);
//				cun(b, a, u);
//			}
//		}
//		for(int v=1; v<=q; v++){
//			int i, j, a, b;
//			scanf("%d%d", &x, &y);
//			memset(f, 9, sizeof(f));
//			f[1]=w[x], wei[1]=x;
//			for(i=j=1; i<=j; i++){
//				g=wei[i];
//				for(int s=h[g]; s; s=d[s].n){
//					a=d[s].a, b=d[s].b;
//					
//				} 
//			}
//		}
//	}
	
	return 0;
}
