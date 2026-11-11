#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MAXN = 5e5 + 7;
int n, l, r, arr[MAXN];
ull m;
ll ans = 0, sum[MAXN];

ull solve(int a, int b){
	return (b - a) * arr[b] - sum[b - 1] + sum[a - 1];
}
ll max(ll a, ll b){
	if(a > b) return a;
	else return b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	sort(arr + 1, arr + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];
	l = r = 1;
	while(r <= n){
		if(solve(l, r) <= m){
			ans = max(r - l + 1, ans);
			++ r;
		} else{
			++ l;
			if(l > r) ++ r;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
