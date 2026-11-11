#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
bool cmp(int x, int y){
	return x>y;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn=0;
	for(int k = 0; k < 30; k++){
		int cnt=0;
		for(int i = 1; i <= n; i++){
			if(a[i]&(1<<k)){
				cnt++;
			}
		}
		if(cnt>=m){
			maxn=k;
		}
	}
	sort(a+1, a+n+1, cmp);
	int ans=(1ll<<31)-1, cnt=0;
	for(int i = 1; i <= n; i++){
		if(cnt==m) break;
		if(a[i]&(1<<maxn)){
			cnt++;
			ans&=a[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
