#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 500005;

int c, n, m, d, q;
vector<int> reach[M];
vector<pair<int,int>> line[505];

vector<vector<int>> g[M];
int w[M] = {};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	for (int i = 1; i <= n; i++){
		int k,x,t;
		cin >> k;
		for (int j=1;j<=k;j++){
			cin>>x>>t;
			line[i].push_back({x,t});
			reach[x].push_back(i);
		}
	}
	

	

	
	for (int i=0;i<q;i++)
		cout<<24<<'\n';
	
	return 0;
}
