#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	/*fopen("crad.in", cin);
	fopen("crad.out", cout);*/
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	return 0;
}
