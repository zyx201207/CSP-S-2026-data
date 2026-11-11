#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[5005], x[3005];
bool check(char b, string s){
	int l = 0, r = s.size() - 1, mid;
	while(l <= r){
		mid = (l + r) / 2;
		if (s[mid] == b)return 0;
		else if (s[mid] < b){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return 1;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n <= 5000){
		for (int i = 1; i <= n; i++){
			string b = "", c = "", d = "";
			for (int j = i; j <= n; j++){
				b += a[j] + '0';
			}
			for (int j = 0; j < b.size(); j++){
				sort(c.begin(), c.end());
				if (check(b[j], c) == 0){
					d = "";
					d += b[j];
				}
				else{
					d += b[j];
				}
				c = d;
			}
			for (int j = 0; j < d.size(); j++){
				x[d[j] - '0']++;
			}
		}
		for (int i = 1; i <= m; i++){
			cout << x[i] << " ";
		}
	}
	return 0;
}
