#include<bits/stdc++.h>
#define ll long long
#define du double 
using namespace std;

const int M=5e5+5;//最大值 
int w[M];
bool mp[50][305][305];
int c,n,m,d,q;
int minn=1e9+5;
bool mpp[505][M];
int t[505][25];
//c编号,n地铁线路数,m地铁站数,d最多几条线路,q出行计划数
void dfs(int ti,int xian,int zhan,int mb){
	//时间 线路 站台 目标站 
	if(zhan==mb){
		//从线路到目标的站台 
		minn=min(minn,ti+t[xian][zhan]);
		//cout<<xian<<"  "<<ti<<endl;
		return;
	}
	
	for(int i=1;i<=m;++i){//继续走 
		if(mp[xian][zhan][i]==1){
			mp[xian][i][zhan]=0;
			dfs(ti,xian,i,mb);
			mp[xian][i][zhan]=1;
		}
	}
	
	for(int i=1;i<=n;++i){//换路线 
		if(mpp[i][zhan]==1 && i!=xian){
			mpp[i][zhan]=0;
			dfs((ti+t[xian][zhan]+t[i][zhan]),i,zhan,mb);
			mpp[i][zhan]=1;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//c编号,n地铁线路数,m地铁站数,d最多几条线路,q出行计划数
	
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	int T=-1,pdt=1;
	for(int i=1;i<=n;++i){
		int tt;
		cin>>tt;
		int x[25];
		cin>>x[1];
		cin>>t[i][x[1]];
		if(T==-1)T=t[i][x[1]];
		for(int j=2;j<=tt;++j){
			cin>>x[j];
			cin>>t[i][x[j]];
			mpp[i][x[j]]=1;mpp[i][x[j-1]]=1;
			
			mp[i][x[j-1]][x[j]]=1;mp[i][x[j]][x[j-1]]=1;
			if(T!=t[i][x[j]])pdt=0;
		}
	}
	//访问  
//c编号,n地铁线路数,m地铁站数,d最多几条线路,q出行计划数 
	
		while(q--){
			minn=1e9+5;
			int mb1,mb2,ti=0;
			cin>>mb1>>mb2;
			ti+=w[mb1];//从mb1站口走到站台的时间 
			//cout<<t[1][2]<<endl;
			for(int i=1;i<=n;++i){
				if(mpp[i][mb1]==1){
					ti+=t[i][mb1];
					dfs(ti,i,mb1,mb2);
					ti-=t[i][mb1];
					//深搜查找方案 
				}
			}
			minn=minn+w[mb2];//从mb2站台走到站口的时间 
			cout<<minn<<endl;
		}
	return 0;
}
