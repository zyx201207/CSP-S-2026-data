#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long pre[500005];
bool cmp(long long a, long long b){
	return a > b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	bool flag = true;
	bool flag1 = true;
	int brat = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != i){
			flag = false;
		}
		if (i == 2 || i == 1){
			brat = a[2] - a[1];
		}
		else{
			if (a[i] - a[i-1] != brat){
				flag1 = false;
			}
		}
	}
	if (flag){
		long long sum = 0;
		for (int i = 1; i <= 500005; i++){
			if (sum + i > m){
				cout << i;
				return 0;
			}
			sum += i;
		}
	}
	if (flag1){
		long long sum = 0;
		for (int i = 1; i <= 500005; i++){
			if (sum + i * brat > m){
				cout << i;
				return 0;
			}
			sum += i * brat;
		}
	}
	sort(a+1, a+1+n, cmp);
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + (a[i] - a[i+1]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int anss=0;
		long long sum = 0;
		for (int j = i+1; j <= n; j++){
			if (sum + pre[j-1]-pre[i-1] <= m){
				anss++;
				sum += (pre[j-1]-pre[i-1]);
			}
			else{
				break;
			}
		}
		ans = max(ans, anss+1);
	}
	cout << ans;
	return 0;
}

