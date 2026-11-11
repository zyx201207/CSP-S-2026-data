#include<bits/stdc++.h>
#define int long long
#define F(i,j,k) for(int i=(j);i<=(k);i++)
#define dF(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int MAXN=500+5,MAXM=5e5+5,inf=1e18;
int c,n,m,d,q,w[MAXM];
vector<pair<int,int>>G[MAXM];
int dis[MAXN][MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	F(i,1,m)cin>>w[i];
	F(i,1,n){
		int len,x,l;cin>>len;
		F(j,1,len){
			cin>>x>>l;G[x].push_back({i,l});
		}
	}
	F(i,1,n)F(j,1,n)dis[i][j]=inf;
	F(i,1,n)dis[i][i]=0;
	F(i,1,m){
		int l=G[i].size();
		F(j,0,l-1)F(k,j+1,l-1){
			auto [v1,w1]=G[i][j];
			auto [v2,w2]=G[i][k];
			dis[v1][v2]=min(dis[v1][v2],w1+w2);
			dis[v2][v1]=min(dis[v2][v1],w1+w2);
		}
	}
	F(k,1,n)F(i,1,n)F(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=w[x]+w[y],mn=inf;
		int l1=G[x].size(),l2=G[y].size();
		F(i,0,l1-1)F(j,0,l2-1){
			auto [v1,w1]=G[x][i];
			auto [v2,w2]=G[y][j];
			mn=min(mn,dis[v1][v2]+w1+w2);
		}
		cout<<ans+mn<<"\n";
	}
}