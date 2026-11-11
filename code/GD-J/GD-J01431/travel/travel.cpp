// 100 pts
#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	string e = b.substr(0, 2),
		   f = d.substr(0, 2);
	char g = b.back(),
		 h = d.back();
	int x = (a == c), y = (x && (e == f)), i = y && ((g <= 'C') == (h <= 'C')), j = i && ((abs(g - h) == 1) || (g == 'D' && h == 'F') || (g == 'F' && h == 'D'));
	cout << x << y << i << j;
	return 0;
}
