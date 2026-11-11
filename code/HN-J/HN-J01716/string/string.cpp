#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, ans, a[N];
char c[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1, j = n; i < j;){
		while(c[i] == c[i + 1] && i < j){
			a[i + 1] += a[i];
			i++;
		}
		while(c[j] == c[j - 1] && i < j){
			a[j - 1] += a[j];
			j--;
		}
		if(a[i] > a[j]){
			if(c[i] != c[j]){
				ans += a[j];
			}
			a[i] -= a[j];
			a[j] = 0;
			j--;
		} else{
			if(c[i] != c[j]){
				ans += a[i];
			}
			a[j] -= a[i];
			a[i] = 0;
			i++;
		}
	}
	cout << ans;
	return 0;
}

