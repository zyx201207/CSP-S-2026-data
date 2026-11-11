#include <iostream>
using namespace std;

int a, b;

string pa, pb;

int aabs(int x) {
	if(x < 0) return -x;
	return x;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> pa >> b >> pb;
	if(a != b) cout << "0000";
	else if(pa[0] != pb[0] || pa[1] != pb[1]) cout << "1000";
	else if((pa[2] <= 'C' && pb[2] >= 'D') || (pa[2] >= 'D' && pb[2] <= 'C')) cout << "1100";
	else if(aabs(pa[2] - pb[2]) >= 2) cout << "1110";
	else cout << "1111";
} 

// Red

// CSP ¼õ J ³ýÒÔ S ºÜÄÑ 
