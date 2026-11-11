#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
long long dis[N][N];
vector<pair<int,int>> p[M];
void Floyd(){F(k,1,n)F(i,1,n)F(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);}
long long solve(int l,int r){
	long long ans=1e18;
	F(i,0,p[l].size()-1)F(j,0,p[r].size()-1){
		int a=p[l][i].first,b=p[r][j].first,w=p[l][i].second+p[r][j].second;
		ans=min(ans,dis[a][b]+w);
	}return ans;
}int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;memset(dis,0x3f,sizeof(dis));F(i,1,n) dis[i][i]=0;
	F(i,1,m) cin>>w[i];
	F(i,1,n){int k;cin>>k;F(j,1,k){int a,t;cin>>a>>t,p[a].push_back({i,t});}}
	F(i,1,m)F(j,0,p[i].size()-1)F(k,j+1,p[i].size()-1){
		int a=p[i][j].first,b=p[i][k].first;long long w=p[i][j].second+p[i][k].second;
		dis[a][b]=dis[b][a]=min(dis[a][b],w);
	}Floyd();
	F(i,1,q){int l,r;cin>>l>>r,cout<<solve(l,r)+w[l]+w[r]<<'\n';}
	return 0;
}
