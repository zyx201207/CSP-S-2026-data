#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510;
const int M = 5e5 + 7;
const int Q = 1e5 + 7;
ll d[N][N],w[M];
int testid,n,m,ct,q;

vector<pair<int,ll> > point[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int _ = 1;//cin >> _;
	while(_--){
		cin >> testid >> n >> m >> ct >> q;
		for(int i=1;i<=m;i++)cin >> w[i];
		memset(d,0x3f,sizeof d);
		for(int i=1;i<=n;i++)d[i][i] = 0;
		for(int i=1;i<=n;i++){
			int k;cin >> k;
			for(int j=1;j<=k;j++){
				ll pt,tm;cin >> pt >> tm;
				for(auto r:point[pt]){
					int c = r.first;ll ds = r.second;
					d[i][c] = min(d[i][c],tm+ds);
					d[c][i] = min(d[c][i],tm+ds);
				}
				point[pt].push_back({i,tm});
			}
		}
//		for(int i=1;i<=m;i++){
//			cerr << i << "------------------------------------\n";
//			for(auto r:point[i]){
//				cerr << r.first << " " << r.second << "\n";
//			}
//		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
		
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				cout << d[i][j] << " \n"[j==n];
		
		
		for(int i=1;i<=q;i++){
			int x,y;cin >> x >> y;
			ll ans = 9e18;
			for(auto r1:point[x])
				for(auto r2:point[y])
					ans = min(ans,w[x] + w[y] + r1.second + r2.second + d[r1.first][r2.first]);
			cout << ans << "\n";
		}
	}
	return 0;
}

/*
Code by mid27_(luogu)welcome to follow me~
Use lyt's 10 life to let my code get full scores!!!!!!!!!!!!!!!!!!!!!!!!! 
*/



