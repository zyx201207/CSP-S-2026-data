#include<bits/stdc++.h>
#define pil pair<int, long long>
using namespace std;

int c, n, m, d, q, k[505];
long long w[500005], dis[505][505];
vector<pil> a[505];
vector<pil> dx[500005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		a[i].resize(k[i]);
		for(int j = 0; j < k[i]; j++){
			scanf("%d%lld", &a[i][j].first, &a[i][j].second);
			dx[a[i][j].first].push_back({i, a[i][j].second});
		}
		sort(a[i].begin(), a[i].end(), [](const pil &b, const pil &c){
			return b.first < c.first;
		});
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int mv1 = 0, mv2 = 0;
			while(mv1 < (int)a[i].size() && mv2 < (int)a[j].size()){
				if(a[i][mv1].first == a[j][mv2].first){
					dis[i][j] = min(dis[i][j], a[i][mv1].second + a[j][mv2].second);
					dis[j][i] = min(dis[j][i], a[i][mv1].second + a[j][mv2].second);
					mv1++;
					mv2++;
				}else if(a[i][mv1].first < a[j][mv2].first){
					mv1++;
				}else{
					mv2++;
				}
			}
		}
	}
	for(int kk = 1; kk <= n; kk++){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++) dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][kk] + dis[kk][j]);
		}
	}
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		long long sum = w[l] + w[r], minn = 1e18;
		for(int i = 0; i < (int)dx[l].size(); i++){
			for(int j = 0; j < (int)dx[r].size(); j++){
				minn = min(minn, dx[l][i].second + dx[r][j].second + dis[dx[l][i].first][dx[r][j].first]);
			}
		}
		printf("%lld\n", sum + minn);
	}
	return 0;
}
