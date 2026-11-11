#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define N 500005
ll n, m, a[N], cost[N];//记录已经花费 
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll ans = 0, tmp_c = 0, tmp_l = 0;
	sort(a+1, a+n+1);
	for(int i = 1;i <= n;i++){
		tmp_c = 0;
		for(int j = i-tmp_l+1;j <= i;j++){
			cost[j]+=(a[i]-a[j]);
			tmp_c += cost[j];
		}
		tmp_l++;
		while(tmp_c > m){
			tmp_c -= cost[i-tmp_l+1];
			tmp_l--;
		}
		ans = max(ans, tmp_l);
	}
	cout << ans << "\n";
	return 0;
}
