#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#ifdef DEBUG
void dbg(){cerr<<endl;}
template<typename A,typename...B>void dbg(A a,B...b){cerr<<a<<" ",dbg(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", dbg(x)
#else
#define debug(...) (void)1
#endif

const int N=5e5+10,M=514;
i64 dis[M][M];
i64 w[N];
int ct[M];
vector<int>v[M];
i64 t[N*21];
int cnt;
vector<pair<int,int>>which[N];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,63,sizeof(dis));
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,m,n,d,q;//n µãÊý 
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1,x;i<=m;i++){
		cin>>ct[i];
		for(int j=1;j<=ct[i];j++) cin>>x>>t[cnt],which[x].emplace_back(i,cnt),cnt++;// which, t which
	}
  for(int i=1;i<=n;i++){
  	int di=which[i].size();
  	for(int x=0;x<di;x++)
  		for(int y=x+1;y<di;y++){
  			auto &[c,tc]=which[i][x];
  			auto &[d,td]=which[i][y];
  			dis[c][d]=min(dis[c][d],t[tc]+t[td]);
  			dis[d][c]=dis[c][d];
//  			dis[which[i][x].first][y]=min(dis[x][y],t[which[i][x].second]+t[which[i][y].second]);
			}
	}
	for(int i=1;i<=m;i++)dis[i][i]=0;  
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	
	while(q--){
		int x,y;cin>>x>>y;
		i64 res=dis[0][0];
		for(auto &[c,tc]:which[x])
			for(auto &[d,td]:which[y]){
				res=min(res,t[tc]+t[td]+dis[c][d]);
			}
		res+=w[x]+w[y];
		cout<<res<<'\n'; 
	}
	return 0;
} 
