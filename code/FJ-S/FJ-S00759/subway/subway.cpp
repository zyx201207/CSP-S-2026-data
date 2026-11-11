#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int M=5e5+16;
int c,n,m,d,q,w[M];
vector<pair<int,int> > xl[M];
int dp[516][516];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			xl[a].push_back({i,t});//线路编号，耗时
		}
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(auto x:xl[i]){
			for(auto y:xl[i]){
				if(x==y)continue;
				dp[x.first][y.first]=min(dp[x.first][y.first],x.second+y.second);//从x（列车上）换线到y的花费 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				if(i==k or j==k)continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(;q;q--){
		int x,y;cin>>x>>y;
		int ans=2e9,res;
		for(auto i:xl[x]){
			for(auto j:xl[y]){
				if(i.first==j.first)res=w[x]+w[y]+i.second+j.second;
				else res=w[x]+w[y]+i.second+j.second+dp[i.first][j.first];
				ans=min(ans,res);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
E:
cd E:\FJ-S00759\subway
fc .\subway.out .\subway5.ans
*/ 
