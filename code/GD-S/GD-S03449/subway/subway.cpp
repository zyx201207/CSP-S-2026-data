#include<bits/stdc++.h>
using namespace std;
int w[500010],k[510];
long long mp[510][510];
vector<pair<int,long long>> a[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d" ,&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d" ,&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&k[i]);
		for(int j = 1;j <= k[i];j++){
			int aa,tt;
			scanf("%d%d" ,&aa,&tt);
			a[aa].push_back({i,tt});
		}
		for(int j = 1;j <= n;j++){
			mp[i][j] = 1e18;
		}
		mp[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		int lenn = a[i].size();
		for(int j = 0;j < lenn;j++){
			for(int jj = j + 1;jj < lenn;jj++){
				mp[a[i][j].first][a[i][jj].first] = min(mp[a[i][j].first][a[i][jj].first],a[i][j].second + a[i][jj].second);
				mp[a[i][jj].first][a[i][j].first] = min(mp[a[i][jj].first][a[i][j].first],a[i][jj].second + a[i][j].second);
			}
		}
	}
	for(int kk = 1;kk <= n;kk++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				mp[i][j] = min(mp[i][j],mp[i][kk] + mp[kk][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d" ,&x,&y);
		long long ans = 1e18;
		int lex = a[x].size(),ley = a[y].size();
		for(int i = 0;i < lex;i++){
			for(int j = 0;j < ley;j++){
				ans = min(ans,a[x][i].second + mp[a[x][i].first][a[y][j].first] + a[y][j].second);
			}
		}
		printf("%lld\n" ,ans + w[x] + w[y]);
	}
	return 0;
} 
