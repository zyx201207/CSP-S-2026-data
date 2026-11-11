#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
vector< pair<int,int> > l[505];
vector< pair<int,int> > s[500005];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int a ,w;
			scanf("%d%d",&a,&w);
			l[i].push_back({a ,w});
			s[a].push_back({i ,w});
		}
	}
	while(q--){
		ans = 0;
		int u ,v;
		cin >> u >> v;
		ans += (w[u] + w[v]);
		for(int i = 0;i < n;i++){
			if(s[u][i].first == s[v][i].first){
				ans += (s[u][i].second + s[v][i].second);
				break;
			} else{
				for(int j = 1;j <= m;j++){
					if(j == u || j == v){
						continue;
					}
					for(int k = 0;k < s[j].size();k++){
						if(k == i){
							continue;
						} 
						if(s[u][i].first == s[j][i].first && s[v][i].first == s[j][k].first){
							ans += (l[s[u][i].first][i].second + l[s[j][i].first][i].second + l[s[j][k].first][k].second + l[s[v][i].first][i].second);
							break;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
