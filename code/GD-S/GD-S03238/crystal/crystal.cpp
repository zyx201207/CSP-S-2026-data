#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
#define N 500010

unsigned long long n, m;
ll a[N];
unsigned long long pre[N];
ll ans = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(ll i = 2;i <= n; i++){
		pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	for(ll i = 1, j = 2;j <= n; j++){
		ll s = pre[j] - (i - 1) * (a[j] - a[i - 1]) - pre[i - 1];;
		while(s > m){
			i ++;
			s = pre[j] - (i - 1) * (a[j] - a[i - 1]) - pre[i - 1];
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans;
	return 0;
}
