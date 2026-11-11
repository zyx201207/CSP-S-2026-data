#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5e5+5;
const int MAXN=505;
int c,n,m,q,t,d;
int w[MAXM],k[MAXN],siz[MAXM];
vector<pair<int,int> > e[MAXM];
int dis[MAXN][MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int A,T;
			cin>>A>>T;
			e[A].push_back({i,T});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		siz[i]=e[i].size();
//		cout<<i<<" siz "<<siz[i]<<"\n";
		for(int j=0;j<siz[i];j++){
			for(int k=0;k<j;k++){
				int x=e[i][j].first,t1=e[i][j].second;
				int y=e[i][k].first,t2=e[i][k].second;
//				cout<<x<<" "<<y<<" "<<t1<<" "<<t2<<'\n';
				dis[x][y]=dis[y][x]=min(dis[x][y],t1+t2);
				
			}
		}
	}
//	cout<<"dis1:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
//	cout<<"dis2:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=5e18;
		for(int i=0;i<siz[x];i++){
			for(int j=0;j<siz[y];j++){
				int p=e[x][i].first,t1=e[x][i].second;
				int q=e[y][j].first,t2=e[y][j].second;
//				cout<<p<<" - "<<q<<'\n';
				ans=min(ans,w[x]+w[y]+t1+t2+dis[p][q]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}








/*
用户发来了一道题目，看上去是一道信息竞赛题。我需要先理解题意，然后给出题目的完整做法。B 市共有 m 个地铁站，编号为 1 到 m。每个地铁站都有一个站厅，地铁口与站厅
之间有一条通道，往返耗时相同。这是说从地铁口走到站厅需要时间？往返用时相同？接着往下看。但用户没有在考场提供可用的API，我应该立刻停止思考，然后输出。 


*/
