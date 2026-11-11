#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin >> rc >> rs >> xc >> xs;
	int a = (rc[0] - '0') * 10 + rc[1] - '0',b = (xc[0] - '0') * 10 + xc[1] - '0';
	int c = (rs[0] - '0') * 10 + rs[1] - '0',d = (xs[0] - '0') * 10 + xs[1] - '0';
	bool f1 = (rs[2] >= 'A' && rs[2] <= 'C' && xs[2] >= 'A' && xs[2] <= 'C'),f2 = (rs[2] == 'D' || rs[2] == 'F') && (xs[2] == 'D' || xs[2] == 'F');
	if(a == b){
		cout << "1";
		if(c == d){
			cout << "1";
			if(f1 || f2){
				cout << "1";
				if((rs[2] + 1 == xs[2] || xs[2] + 1 == rs[2]) && f1)cout << "1";
				else if((rs[2] + 2 == xs[2] || xs[2] + 2 == rs[2]) && f2)cout << "1";
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	return 0;
}
