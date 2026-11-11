#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 500005;
int c,n,m,d,q;
int a[20][M];
int t[20][M];
struct node{
	int a[20];
	long long t[20];//站厅走到第 i 条线路的站台
	long long w;
}o[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%lld",&o[i].w);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int  j = 1;j <= k;j++){
			int u,v;
			scanf("%d%d",&u,&v);
			o[u].a[i] = i;
			o[u].t[i] = v;
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans = LLONG_MAX;
		bool insameway = 0;
		int way;
		for(int j = 1;j <= 20;j++){
			if(o[x].a[j] == o[y].a[j] && o[x].a[j] != 0){
				insameway = 1;
				way = j;
			}
		}
		if(insameway){
			ans =o[x].w + o[x].t[way]+o[y].w+o[y].t[way];
		}else{
			for(int z= 1;z <= m;z++){
				for(int u = 1;u <= 20;u++){
					for(int v = 1;v <= 20;v++){
						if(o[x].a[u] == o[z].a[u] && o[z].a[v] == o[y].a[v]&&o[z].a[u]!=0&&o[z].a[v]!=0){
							long long sum = o[x].w+o[x].t[u]+o[z].t[u]+o[z].t[v]+o[y].w+o[y].t[v];
							ans=min(ans,sum);
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
