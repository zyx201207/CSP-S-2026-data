#include<bits/stdc++.h>

using namespace std;

int a, b, c, d;
char e, f;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b >> e >> c >> d >> f;
	if(a != c) cout << "0000";
	else if(b != d) cout << "1000";
	else if(e <= 'C' && f > 'C' || e > 'C' && f <= 'C') cout << "1100";
	else if(abs(e - f) != 1) cout << "1110";
	else cout << "1111";
	return 0;
}
/*

*/
