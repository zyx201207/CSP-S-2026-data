
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 500 + 5,M = 5e5 + 5;
ll f[N][N];
ll val[M];
vector<ll> a[N],t[N];
vector<pii> l[M];
int k[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			l[x].push_back({i,j - 1});
//			cerr<<x<<" "<<l[x].size()<<'\n';
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<l[i].size();j++){
			for(int k=0;k<l[i].size();k++){
				int num = l[i][j].first,pos = l[i][j].second,num2 = l[i][k].first,pos2 = l[i][k].second;
				if(j == k){
					f[num][num2] = 0;
				}else{
					f[num][num2] = min(f[num][num2],t[num][pos] + t[num2][pos2]);
				}
			}
		}
	}	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll res = 9e18;
		for(int i=0;i<l[u].size();i++){
			for(int j=0;j<l[v].size();j++){
				int numu = l[u][i].first,posu = l[u][i].second;
				int numv = l[v][j].first,posv = l[v][j].second;
//				cerr<<u<<" "<<v<<" "<<numu<<" "<<numv<<" "<<f[numu][numv]<<" "<<t[numu][posu] + t[numv][posv] + val[u] + val[v]<<'\n';
				res = min(res,f[numu][numv] + t[numu][posu] + t[numv][posv] + val[u] + val[v]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
*/
