#include <bits/stdc++.h>
#define ll long long
#define _for(i, x, y) for(int i = x;i <= y;i++)
#define fre(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;
ll n, m, a[200005];
bool cmp(ll x, ll y){
	return x > y;
}
int main(){
	fre("and")
	cin >> n >> m;
	_for(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	_for(i, 2, m) a[i] &= a[i - 1];
	cout << a[m];
	return 0;
}
