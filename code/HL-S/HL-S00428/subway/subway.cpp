#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll basic[555555];
ll sheet[555][555];
vector<pair<ll,ll>> sta[555555];
pair<ll,ll> mk(ll fir,ll sec){
	pair<ll,ll> outp;
	outp.first = fir;
	outp.second = sec;
	return outp;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j){
				sheet[i][j] = 0;
			}
			else{
				sheet[i][j] = 1e18;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld",&basic[i]);
	}
	for(int i = 1;i <= n;i++){
		ll k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			ll num,t;
			scanf("%lld",&num);
			scanf("%lld",&t);
			sta[num].push_back(mk(i,t));
		}
	}
	for(int i = 1;i <= m;i++){
		for(int a = 0;a < (int)sta[i].size();a++){
			for(int b = 0;b < (int)sta[i].size();b++){
				sheet[sta[i][a].first][sta[i][b].first] = min(sheet[sta[i][a].first][sta[i][b].first],sta[i][a].second + sta[i][b].second);
				sheet[sta[i][b].first][sta[i][a].first] = min(sheet[sta[i][b].first][sta[i][a].first],sta[i][a].second + sta[i][b].second);				
			}
		}
	}
	for(int mid = 1;mid <= n;mid++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				sheet[i][j] = min(sheet[i][j],sheet[i][mid]+sheet[mid][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		ll x,y;
		cin >> x >> y;
		ll ans = 1e18;
		for(int i = 0;i < (int)sta[x].size();i++){
			for(int j = 0;j < (int)sta[y].size();j++){
				ans = min(ans,sta[y][j].second+sta[x][i].second+sheet[sta[x][i].first][sta[y][j].first]);
			}
		}
		cout << ans + basic[x] + basic[y] << '\n';
	}
	return 0;
}