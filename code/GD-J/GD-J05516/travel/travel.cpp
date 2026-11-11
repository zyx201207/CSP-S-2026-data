#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	bool fl = true;
	string x_,y_;
	cin >> x >> x_ >> y >> y_;
	int xline = (x_[0]-'0')*10 + (x_[1]-'0');
	int yline = (y_[0]-'0')*10 + (y_[1]-'0');
	char xseat = x_[2];
	char yseat = y_[2];
	if (x == y){
		cout << 1;
	}
	else{
		fl = false;
		cout << 0;
	}
	if ((xline == yline) && fl){
		cout << 1;
	}
	else{
		fl = false;
		cout << 0;
	}
	if (fl){
		if (xseat == 'D' || xseat == 'F'){
			char n = 'D' + 'F' - xseat;
			if (n == yseat) cout << 11;
			else cout << "00";
		}
		else{
			if (xseat == 'A' && yseat == 'B') cout << 11;
			else if (xseat == 'B' && yseat == 'A') cout << 11;
			else if (xseat == 'B' && yseat == 'C') cout << 11;
			else if (xseat == 'C' && yseat == 'B') cout << 11;
			else if (yseat == 'D' || yseat == 'F') cout << "00";
			else cout << 10;
			
		}
	}
	else{
		cout << "00";
	}
	return 0;
}
