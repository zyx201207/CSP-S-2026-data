#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	string s3, s4;
	cin >> s3 >> s4;
	
	if(s1 != s3) 
		cout << "0000\n", exit(0);
	if(s2[0] != s4[0] || s2[1] != s4[1])
		cout << "1000\n", exit(0);
	if((s2[2] <= 'C') != (s4[2] <= 'C'))
		cout << "1100\n", exit(0);
	if(abs(s2[2] - s4[2]) > 1)
		cout << "1110\n", exit(0);
	if(abs(s2[2] - s4[2]) <= 1)
		cout << "1111\n", exit(0);
	return 0;
}
