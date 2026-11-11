#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=505;
const int M=5e5+5;
const ull inf=1e16+5;
int c,n,m,d,q;
ull ww[M],a[N][N],t[N][N];
vector <pair<ull,ull> > ver[M];
ull dis[N][N];
void solve(){
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;++i){
		cin >> ww[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin >> k;
		for(int j=1;j<=k;++j){
			ull a,t;
			cin >> a >> t;
			ver[a].emplace_back(make_pair(i,t));
		}
	}
	
	for(int i=1;i<=m;++i){
		for(int j=0;j<ver[i].size();++j){
			for(int k=0;k<ver[i].size();++k){
				ull a1=ver[i][j].first,t1=ver[i][j].second;
				ull a2=ver[i][k].first,t2=ver[i][k].second;
				dis[a1][a2]=min(dis[a1][a2],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				//cout << i <<  " " << j << " " << dis[i][j] << '\n';
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;++i){
		int x,y;
		cin >> x >> y;
		ull ans=inf;
		for(int j=0;j<ver[x].size();++j){
			for(int k=0;k<ver[y].size();++k){
				ull a1=ver[x][j].first,t1=ver[x][j].second;
				ull a2=ver[y][k].first,t2=ver[y][k].second;
				ans=min(dis[a1][a2]+t1+t2,ans);
			}
		}
		cout << ans+ww[x]+ww[y] << '\n';
	}
	
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
} 
