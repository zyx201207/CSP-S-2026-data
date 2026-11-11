#include<bits/stdc++.h>
using namespace std;
const long long N = 5000 + 7;
long long n,m,c,d,q,w[N],a[N][N],t[N][N],vis[N],ans,x,y,k;
vector<pia<long long,long long>> e[N];
int main(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> a[i][j] >> t[i][j]; 
		}
		for(int j = 2;j <= k;j ++){
			e[j].push_back({i,a[i][j - 1]});
			e[a[i][j - 1]].push_back({i,j});
		}
	}
	for(int i = 1;i <= q;i ++){
		cin >> x >> y;
		
	}
}
