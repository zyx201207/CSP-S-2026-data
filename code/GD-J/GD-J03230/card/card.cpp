#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
const int maxn = 510;
int n, m;
int a[maxn];
int res[maxn];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		bool vis[maxn] = {0}, can[maxn] = {0};
		int pre[maxn] = {0};
		for (int j = i; j <= n; j++){
			if (vis[a[j]]){
				for (int k = pre[a[j]] ; k < j; k++){
					can[k] = true;
				}
				pre[a[j]] = j;
			}else{
				vis[a[j]] = true;
				pre[a[j]] = j;
			}
		}
		for (int j = i; j <= n; j++){
			if (!can[j]){
				res[a[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << res[i] << " ";
	}
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

