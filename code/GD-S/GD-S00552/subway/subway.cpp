#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int N = 505,M = 500005,D = 25,Q = 100005;
int c,n,m,d,q;
long long w[M];
vector<pair<int,long long>> edge[M];
long long dis[N][N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		int id,cost;
		while(k--){
			cin >> id >> cost;
			edge[id].emplace_back(i,cost);
		}
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dis[i][j] = 4e18;
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int i = 1;i <= m;i++)
		for(auto pp : edge[i])
			for(auto qq : edge[i]){
				if(pp == qq) continue;
				dis[pp.first][qq.first] = dis[qq.first][pp.first] = min(dis[pp.first][qq.first],1ll * pp.second + qq.second);
			}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while(q--){
		int x,y;
		cin >> x >> y;
		long long ans = 9e18;
		for(auto st : edge[x])
			for(auto ed : edge[y])
				ans = min(ans,w[x] + w[y] + st.second + ed.second + dis[st.first][ed.first]);
		cout << ans << '\n';
	}
	return 0;
}