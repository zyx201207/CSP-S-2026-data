#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
long long c,n,m,d,q;
long long w[N];//从第i个地铁口到地铁站的时间
long long k[N];//第i号线经过的地铁站数
long long line[N][N];//第i号线经过的第j个地铁站编号 
bool a[N][N];//i号线是否经过j站台
long long t[N][N];//第i号线到第j个站厅需要的时间
long long start,ended,ans=9e18;//起始站和终点站以及最短步行距离
//地铁口->站厅->第i号线的站台 
void dfs(long long nowstation,long long nowline,long long sum,int time){
	if(nowstation==ended){
		ans=min(ans,sum+w[ended]);
		return;
	}
	if(time>n+1) return;
	for(int i=1;i<=n;i++){	//遍历所有号线，看看哪一辆有经过当前地铁站 
		if(a[i][nowstation]){		//i号线有经过当前地铁站的话上车看能到达哪几个地铁站 
			for(int j=1;j<=k[i];j++){		//遍历第i号线经过的所有车站 
				dfs(line[i][j],i,sum+t[i][nowstation]+t[i][j],time+1);		//到i号线的第j个站台，现在在i号线，行走距离加原来的站厅到第i号线的站台加上第i号线的站台到第j个地铁站的站厅 
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long x;
			cin>>x>>t[i][j];
			a[i][x]=1;
			line[i][j]=x;
		}
	}
	while(q--){
		ans=9e18;
		cin>>start>>ended;
		dfs(start,1,w[start],1);
		cout<<ans<<endl;
	}
	return 0;
} 
