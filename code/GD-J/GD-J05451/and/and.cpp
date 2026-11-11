#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp_pre[200005], n, m, dp_now[200005], a[200005], maxn;
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		dp_pre[i] = a[i];
	}
	//Æ­·Ö 
	for(int k = 2; k <= m; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j < i; ++j){
				dp_now[i] = max(dp_now[i], dp_pre[j]&a[i]);
			}
		}
		swap(dp_now, dp_pre);
		fill(dp_now+1, dp_now+n+1, 0);
	}
	for(int i = 1; i <= n; ++i){
		maxn = max(dp_pre[i], maxn);
	}
	cout << maxn;
}
