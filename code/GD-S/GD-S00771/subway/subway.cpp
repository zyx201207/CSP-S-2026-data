#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int w[1000000], a[1000000], t[1000000], k[1000000];
int x[1000000], y[1000000];
int i, j;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(i=0;i<m;i++){
		scanf("%d", &w[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d", &k[i]);
		for(j=0;j<2*k[i];j++){
			if(j%2==0) scanf("%d", &a[j/2]);
			else scanf("%d", &t[(j/2)+1]);
		}
	}
	for(i=0;i<q;i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	
	return 0;
}

