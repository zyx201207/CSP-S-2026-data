#include<bits/stdc++.h>
using namespace std;
struct xianlu{
	long long k;//线路经过的地铁站数
	long long a[50005];//线路经过的第j个地铁站
	long long t[50005];//从j地铁站的站厅走到线路的站台需要的时间
};
//struct jihua{
//	long long qd;//出行计划的起点所在的地铁站编号
//	long long zd;//终点
//};
long long c;//测试点编号 
long long n;//地铁线路数
long long m;//地铁站数
long long d;//每个地铁做多被几条线路经过
long long q;//出行计划数 
long long w[50005];//从每个地铁站的地铁口走到站厅的时间
xianlu l[50005];
//jihua r[10005];
long long mapp[50005][50005];
//long long lj(long long xx){
//	if(i==zd) return;
//	for(int i=1;i<=m;i++){
//		if(map[qd][i]==1){
//			lj(i);
//		}
//	}
//}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i].k;
		for(int j=1;j<=l[i].k;j++){
			cin>>l[i].a[j]>>l[i].t[j];
			for(int u=j;u>1;u--){
				mapp[l[i].a[u]][l[i].a[u-1]]=1;
			}
		}
	}
	while(q--){
		long long ans=0,qd=0,zd=0;
		cin>>qd>>zd;
		ans+=w[qd];
		if(mapp[qd][zd]==1){
			ans+=w[zd];
		}
		//for(int i=1;i<=m;i++){
		//	if(map[qd][i]==1){
		//		
		//	}
		cout<<ans;
	}
	
	return 0;
}
