#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long cryN, m;
	cin >> cryN >> m;
	vector<long long> crystals(cryN);
	for(int i = 0; i < cryN; i ++){
		cin >> crystals[i];
	}
	cout << rand() << endl;
	return 0;
}
// hyw
