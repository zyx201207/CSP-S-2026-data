#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 2;
long long s[maxn], f[maxn];
long long n, m;
int ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i++)
		f[i] = s[i] - s[i - 1];
	for(int i = 1; i <= n; i++)
		f[i] = f[i - 1] + (i - 1) * f[i];
		
	for(int i = 1, j = 1; i <= n; ){
		if(f[j] - f[i] - (i - 1) * (s[j] - s[i]) <= m){
			ans = max(ans, j - i + 1);
			if(j == n)
				break;
			j++;
		}
		else
			i++;
	}
	cout << ans;
	return 0;
}
//Oct31==Dec25?

