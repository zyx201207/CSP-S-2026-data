#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int ll
#define inf (1e18 + 10)
const int N = 5e5 + 5;
int n, m, a[N], ans[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		string mod;
		for(int j = i;j <= n;j ++){
			char mo = char(a[j] + '0');
			if(mod.find(mo) > mod.size()){
				mod += mo;
			}else{
				mod.erase(mod.find(mo), mod.size() - mod.find(mo));
				mod += mo;
			}
		}
		for(int i = 1;i <= m;i ++){
			char mo = char(i + '0');
			if(mod.find(mo) > mod.size()){
				continue;
			}else{
				ans[i] ++;
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i] << " ";
	}
	return 0;
}
