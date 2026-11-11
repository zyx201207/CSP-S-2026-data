#include<bits/stdc++.h>
#define ll long long
#define DEBUG(x) cerr << #x << " = " << x
using namespace std; 
namespace KinoHimari{
	const int inf = 1e9, N = 5e5 + 5;
	const ll INF = 1e18;
	int n; ll m, a[N], s[N];
	int main(){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		int ans = 0;
		for(int i = 1, j = 1; i <= n; i++){
			while(j < i && (i - j + 1) * a[i] - (s[i] - s[j - 1]) > m) j++;
			ans = max(ans, i - j + 1);
		}
		cout << ans;
		return 0;	
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	return KinoHimari :: main();
}
