#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N=200005;
bool vis[N]={false};
ll n,m,a[N],ans=0;
int dfs(int index) {
	if(index == n + 1){
		ll thisans=0xFFFFFFFFFFFFFFFF,cnt=0LL;
		for(ll i=1;i<=n;i++){
			thisans &= ((vis[i]) ? (cnt++, a[i]) : 0xFFFFFFFFFFFFFFFF);
		}
		ans = max(ans, ((cnt == m) ? thisans : 0));
		return 0;
	}
	for(ll i=index;i<=n;i++){
		vis[i] = true;
		dfs(i + 1);
		vis[i] = false;
	}
	return 0;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}

