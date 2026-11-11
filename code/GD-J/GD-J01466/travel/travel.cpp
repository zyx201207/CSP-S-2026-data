#include <bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ra >> rb >> xa >> xb;
	if (ra == xa) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	bool pai = 1;
	for (int i = 0;i < 2;i++) {
		if (rb[i] != xb[i]) pai = 0;
	}
	if (pai) {
		cout << "1";
	}
	else {
		cout << "000";
		return 0;
	}
	if ((rb[2] > 'C' && xb[2] > 'C' || rb[2] <= 'C' && xb[2] <= 'C') && pai) cout << "1";
	else {
		cout << "00";
		return 0;
	}
	if (rb[2] == 'C' && xb[2] == 'D' || rb[2] == 'D' && xb[2] == 'C') {
		cout << "0";
		return 0;
	}
	if (abs(rb[2] - xb[2]) == 1 && pai) cout << "1";
	else cout << "0"; 
	return 0;
}
