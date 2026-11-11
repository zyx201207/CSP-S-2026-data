#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> q;
int n, m;
long long a[200005];
long long ans = 0;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
		cin >> a[i];
		q.push(a[i]);
	}
	ans = q.top();
	q.pop();
	for(int i = 2; i <= m; i ++){
	    ans &= q.top();
		q.pop();
	}
	cout << ans;
    return 0;
}
