#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
const int M=500010,N=510;
const LL LLmex=(LL)1e18+2;
int c,n,m,d,q;
LL dp[N][N],w[M];
struct node{int lid;LL tim;};
vector<node> vec[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			vec[a].ZPB((node){i,t});
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) dp[i][j]=LLmex;
	for(int i=1;i<=n;++i) dp[i][i]=0;
	for(int i=1;i<=m;++i){
		int siz=vec[i].size();
		for(int x=0;x<siz;++x)
			for(int y=0;y<siz;++y){
				if(x==y) continue;
				int u=vec[i][x].lid,v=vec[i][y].lid;
				dp[u][v]=min(dp[u][v],vec[i][x].tim+vec[i][y].tim);
			}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		int szu=vec[u].size(),szv=vec[v].size();
		LL ans=LLmex;
		for(int i=0;i<szu;++i)
			for(int j=0;j<szv;++j){
				int x=vec[u][i].lid,y=vec[v][j].lid;
				ans=min(ans,dp[x][y]+vec[u][i].tim+vec[v][j].tim+w[u]+w[v]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
input1:

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

output1:

32
17

input2:

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

output2:

35
16

*/
