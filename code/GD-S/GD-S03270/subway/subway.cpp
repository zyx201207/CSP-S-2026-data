#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;//测试点编码、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数 
long long w[500001];//每个地铁口走到站厅需要的时间 
long long k[500],a[501][501],t[501][501];//第i条线路经过的地铁站数、第i条线路经过的第j个地铁站、从该地铁站的站厅走到第i条线路的站台需要的时间 
long long x[100001],y[100001];//第r个出行计划的起点和终点所在的地铁站编号 
long long mp[501][501],ans[100001];//地图、答案 
bool f(long long p,long long q,long long o){
	for(int i=1;i<k[o];i++)
		for(int j=i+1;j<=k[o];j++)
			if((a[o][i]==p&&a[o][j]==q)||(a[o][i]==q&&a[o][j]==p))
				return true;
	return false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++)cin>>w[v];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++)cin>>x[r]>>y[r];
	for(int r=1;r<=q;r++)
		for(int i=1;i<=n;i++)
			if(f(x[r],y[r],i))
				ans[r]+=w[x[r]]+t[i][x[r]]+t[i][y[r]]+w[y[r]];
	for(int r=1;r<=q;r++)cout<<ans[r]<<endl;
	return 0;
}
