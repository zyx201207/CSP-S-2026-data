#include<bits/stdc++.h>
using namespace std;
int n, m, h, as;
int s[500005], ans[300005];
int a[800005];
void solve(int x){
	for (int i = x;i <= n;i++){
		bool is_have = false;
		as += 1;
		int hs = h;
		for (int j = hs;j <= as;j++){
			if (a[j] == s[i]) {
				is_have = true;
				a[as] = s[i];
				h = as;
				break;
			}
		}
		if (!is_have){
			a[as] = s[i];
		}
		cout << h << " " << as << endl;
		for (int j = h;j <= as;j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
	return ;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
    	cin >> s[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++) a[j] = s[i];
		as = n, h = 1;
		solve(i);
		for (int j = h;j <= as;j++) {
			ans[a[j]] += 1;
		}
	}
	for (int j = 1;j <= m;j++) cout << ans[j] << " ";
	return 0;
} 
