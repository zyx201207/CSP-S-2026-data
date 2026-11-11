#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m;
int a[N];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(m == 2){
		int maxn = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++)maxn = max(a[i] & a[j], maxn);
		}
		cout << maxn;
		return 0;
	}else if(m == n){
		int cnt = 1;
		for(int i = 1;i <= n;i++)cnt &= a[i];
		cout << cnt;
		return 0;
	}else if(m == 1){
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}else if(m == n - 1){
		int cnt = 1, maxn = 0;
		for(int i = 1;i <= n;i++){
			cnt = 1;
			for(int j = 1;j <= n;j++){
				if(j == i){
					continue;
				}
				cnt &= a[j];
			}
			maxn = max(cnt, maxn);
		}
		cout << maxn;
		return 0;
	}
	cout << 0;
	return 0;
}

