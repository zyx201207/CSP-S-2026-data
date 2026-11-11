#include <bits/stdc++.h>
using namespace std;
int r, x;
string ra, xa;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r >> ra >> x >> xa;
	if (r == x) {
		cout << "1";
		if (ra[0]== xa[0]&&ra[1]== xa[1]) {
			cout << "1";
			if ((ra[2] =='B' && xa[2] == 'A')||(ra[2] =='C' && xa[2] == 'A')||(ra[2] =='C' && xa[2] == 'B') ||(ra[2] =='A' && xa[2] == 'B')||(ra[2] =='A' && xa[2] == 'C')||(ra[2] =='B' && xa[2] == 'C')||(ra[2] =='F' && xa[2] == 'D')||(ra[2] =='D' && xa[2] == 'F')){
				cout << "1";
				if ((ra[2] =='B' && xa[2] == 'A')||(ra[2] =='C' && xa[2] == 'B') ||(ra[2] =='A' && xa[2] == 'B')||(ra[2] =='B' && xa[2] == 'C')||(ra[2] =='F' && xa[2] == 'D')||(ra[2] =='D' && xa[2] == 'F')) {
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
