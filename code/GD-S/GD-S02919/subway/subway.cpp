#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int maxn = 1010;
int c,n,m,d,q;
int w[maxn];
vector <pair <int , int> > a[maxn];
void solve(){
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int nows , nowt;
			cin >> nows >> nowt;
			a[i].push_back({nows,nowt});
		}
	}
	while (q--){
		int x , y , res = 0;
		cin >> x >> y;
		res = w[x] + w[y];
		for (int i = x; i <= y; i++){
			for (int j = 1; j <= n; j++){
				bool flag = false;
				for (auto now : a[j]){
					if (now.first == i){
						res += now.second;
						flag = true;
						break;
					}
				}
				if (flag){
					break;
				}
			}
		}
		cout << res << endl;
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

