#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N=5e5+10,M=610,inf=1e18;
int c,n,m,d,Q,w[N],kk[N],le[M][M];
vector<pair<int,int>> a[N];
unordered_map<int,int> ma[M];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){cin>>kk[i];for(int j=1,ax,tx;j<=kk[i];j++) cin>>ax>>tx,a[ax].push_back({i,tx}),ma[i][ax]=tx;}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) le[i][j]=(i==j?0:inf);
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			int aj=a[i][j].fi,tj=a[i][j].se;
			for(int k=0;k<j;k++){
				int ak=a[i][k].fi,tk=a[i][k].se;
				le[aj][ak]=le[ak][aj]=min(le[aj][ak],tj+tk);
			}			
		} 
	} 
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) le[i][j]=min(le[i][j],le[i][k]+le[k][j]);
	while(Q--){
		int x,y,ans=inf;cin>>x>>y;
		for(int i=0;i<a[x].size();i++){
			int ai=a[x][i].fi,ti=a[x][i].se;
			for(int j=0;j<a[y].size();j++){
				int aj=a[y][j].fi,tj=a[y][j].se;
				ans=min(ans,le[ai][aj]+w[x]+w[y]+ti+tj);
			}
		}
		cout<<ans<<'\n';
	}	
//	for(int i=1;i<=m;i++){for(int j=1;j<=m;j++) cout<<le[i][j]<<' ';cout<<endl;}
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
写完发现数据范围看错了 
*/
