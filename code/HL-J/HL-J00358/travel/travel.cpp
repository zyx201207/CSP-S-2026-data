#include <iostream>
#include <cmath>
using namespace std;
string a1 , a2 , b1 , b2;
bool a = 1 , b = 1 , c = 1 , d = 1 , e;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	for (int i = 0 ; i < 2 ; i ++) if (a1[i] != b1[i]) a = 0 , b = 0 , c = 0 , d = 0;
	for (int i = 0 ; i < 2 ; i ++) if (a2[i] != b2[i]) b = 0;
	if ((((a2[2] >= 'A' && a2[2] <= 'C' && b2[2] >= 'A' && b2[2] <= 'C') || (a2[2]) >= 'D' || b2[2] >= 'D') == 0) || (a2[2] == 'C' && b2[2] == 'D') || a2[2] == 'D' && b2[2] == 'C' || b == 0) c = 0;
	if (((b2[2] - 1 == a2[2] || b2[2] + 1 == a2[2]) == 0) || (a2[2] == 'C' && b2[2] == 'D') || a2[2] == 'D' && b2[2] == 'C' || b == 0) d = 0;
	cout << a << b << c << d;
}
