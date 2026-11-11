#include<bits/stdc++.h>
using namespace std;
int n, m, k, l;
char a, b;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m >> a >> k >> l >> b;
	cout << (n == k);
	cout << (n == k && m == l);
	cout << (n == k && m == l && (a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D'));
	if (a == 'D') cout << (n == k && m == l && b == 'F');
	else if (b == 'D') cout << (n == k && m == l && a == 'F');
	else cout << (n == k && m == l && (a == b - 1 || a == b + 1));
	return 0;
}
