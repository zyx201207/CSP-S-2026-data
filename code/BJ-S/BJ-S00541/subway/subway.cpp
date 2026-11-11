//for((i=1;i<=4;i++)) do (mv subway$i.in ./subway.in && ./a.out && mv ./subway.in ./subway$i.in && vimdiff subway.out subway$i.ans && mv ./subway.out ./subwat$i.out) done;
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long dis[505][505],w[500005],c,n,m,d,q,tot;
vector<pair<int,long long> > stat[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m; i++) cin >> w[i];
	for(int i = 1,k;i <= n; i++){
		cin >> k;
		for(int j = 1,x,y;j <= k; j++){
			cin >> x >> y;
			stat[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= m; i++) for(auto s : stat[i]) for(auto t : stat[i])
		dis[s.first][t.first] = min(dis[s.first][t.first],s.second+t.second);
	for(int i = 1;i <= n; i++) dis[i][i] = 0;
	for(int k = 1;k <= n; k++) for(int i = 1;i <= n; i++) for(int j = 1;j <= n; j++)
		dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
	while(q--){
		int x,y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(auto s : stat[x]) for(auto t : stat[y])
			ans = min(ans,w[x]+w[y]+s.second+t.second+dis[s.first][t.first]);
		cout << ans << endl;
	}
	//cerr << tot << endl;
	
	return 0;
}
//Time complexity:O(m*d^2+n^3+q*d^2).