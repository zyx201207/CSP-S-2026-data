#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,x,y;
struct Station{
	int w,k;
	map<int,int> a,b;
}lists[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> lists[i].w;
	for(int i=1;i<=n;i++){
		cin >> lists[i].k;
		for(int j=1;j<=lists[i].k;j++) cin >> lists[i].a[j];
		for(int j=1;j<=lists[i].k;j++) cin >> lists[i].b[j];
	}
	printf("测试点编号为%d 地铁线路数为%d 地铁站数为%d 每个地铁站最多被%d条线路经过 出行计划数为%d",c,n,m,d,q);
	
	for(int i=1;i<=m;i++) printf("%d地铁口到站厅的时间为%d\n",i,lists[i].w);
	for(int i=1;i<=n;i++){
		printf("%d号线经过的地铁站数为%d\n",i,lists[i].k);
		for(int j=1;j<=lists[i].k;j++) printf("%d号线经过的第 %d 个地铁站\n",i,lists[i].a[j]);
		for(int j=1;j<=lists[i].k;j++) printf("该地铁站的站厅走到%d号线站台的时间为 %d \n",i,lists[i].a[j]);
	}
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		
	}
	return 0;
}
