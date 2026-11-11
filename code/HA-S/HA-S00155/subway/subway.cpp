#include <bits/stdc++.h>
#include <cstdio>
#define intn long long
using namespace std;
intn c,n,m,d,q,w[500005],a[505][50],ans,x,y
,b[505][50];


int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数

	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i][0];
		for(int j=1; j<=a[i][0]; j++) {
			cin>>a[i][j]>>b[i][j];
		}
	}

//以上为全局数据

	for(int i=1; i<=q; i++) {
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
		return 0;
	}
}
