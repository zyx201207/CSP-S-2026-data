#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, r1, r2;
	char cc1, cc2;
	cin >> c1 >> r1 >> cc1 >>  c2 >> r2 >> cc2;
	// cout << c1 << r1 << cc1 << ' ' << c2 <<
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && r1 == r2) cout << 1;
	else cout <<0;
	if(c1 == c2 && r1 == r2 && (((cc1 == 'A' || cc1 == 'B' || cc1 == 'C') && (cc2 == 'A' || cc2 == 'B' || cc2 == 'C')) || ((cc1 == 'F' || cc1 == 'D') && (cc2 == 'F' || cc2 == 'D')))) cout << 1;
	else cout << 0;
	if(c1 == c2 && r1 == r2 && (((cc1 == 'A' || cc1 == 'B' || cc1 == 'C') && (cc2 == 'A' || cc2 == 'B' || cc2 == 'C')) || ((cc1 == 'F' || cc1 == 'D') && (cc2 == 'F' || cc2 == 'D'))) && (min(cc1, cc2) != 'C' && max(cc1, cc2) != 'D') && (min(cc1, cc2 ) == 'D' || abs(cc1 - cc2) == 1)) cout << 1;
	else cout << 0;
	return 0;
}
