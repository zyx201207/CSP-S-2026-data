#include<bits/stdc++.h>
#define int long long
const int N=505;
const int M=5e5+5;
const int inf=1e18;
using namespace std;
int C,n,m,d,q,w[M],k,x,y,ans,c[N][N];
vector<pair<int,int> >G[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;fill(c[i]+1,c[i]+n+1,inf);c[i][i]=0;
		for(int j=1;j<=k;j++)cin>>x>>y,G[x].push_back({i,y});
	}
	for(int i=1;i<=m;i++){
		for(auto p:G[i]){
			for(auto q:G[i]){
				if(p.first!=q.first){
					c[p.first][q.first]=min(c[p.first][q.first],p.second+q.second);
					c[q.first][p.first]=min(c[q.first][p.first],p.second+q.second);
				}
			}
		}
	}
	for(int z=1;z<=n;z++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][z]+c[z][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;ans=inf;
		for(auto p:G[x]){
			for(auto q:G[y]){
				ans=min(ans,c[p.first][q.first]+p.second+q.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
