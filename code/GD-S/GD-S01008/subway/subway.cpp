#include<bits/stdc++.h>
using namespace std;
const int N=550;
int c;//测试点编号
int m;//station
int n;//line
int d;//最多有d 条线路经过
int q;//q 个出行计划
int ans;
//连通的
//从第xr 个地铁站的地铁口出发
//到达第yr 个地铁站的地铁口
//每次站内换乘都需要 
//从一条线路的站台->到站厅->另一条线路的站台
//总步行时间=进出站+换乘 的步行时间

int w[N];//从每个地铁站口走到站厅 需要的时间
int k[N];
int a[N][N];//第i条线路经过的地铁站
set<int>b[N];//station i->lines 
int t[N][N];//第j个地铁站的站厅->第i条线路的站台需要的时间
bool vis[N];
bool chk[N];

//case A;
int solve1(int st,int ed,int lin){
	if(st==ed)return t[lin][st];
	if(vis[st])return 0;
	if(chk[lin])return 0;
	vis[st]=1,chk[st]=1;
	for(int j=1;j<=k[st];++j){
		int nst=a[lin][j];
		if(nst!=st){
			int cnt=0;
			for(auto i:b[st]){
				if(lin!=i&&!chk[i]){
					cnt=max(solve1(nst,ed,i)+t[lin][st]+t[i][st],cnt);
				}
			}
			return cnt;
		}
	}
	return 0;
}
//case B;
int solve2(int st,int ed,int lin){
	return 0;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool cas1,cas2;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;++i)cin>>w[i];
	int tt=0;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		if(k[i]>2)cas1=1;
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].insert(i);
			if(tt==0)tt=t[i][j];
			if(tt!=t[i][j])cas2=1;
		}
	} 
	while(q--){
		//第r个出行计划的起点和终点所在的地铁站编号
		int xr,yr;cin>>xr>>yr;
		memset(vis,0,sizeof vis);
		ans=w[xr]+w[yr];
//		if(cas1==0){
			int cnt=0;
			//cout<<"size:"<<b[xr].size()<<endl;
			for(auto i:b[xr]){//line
				cnt=max(solve1(xr,yr,i)+t[i][xr],cnt);
				//cout<<"\n--"<<solve1(xr,yr,i)<<endl;
			}
			cout<<cnt+ans<<endl;
			//continue; 
//		}
//		if(cas2==0){
//			cout<<solve2(xr,yr)<<endl;
//			continue;
//		}
		//cout<<solve(xr,yr)<<endl;
	}
	return 0;
}

