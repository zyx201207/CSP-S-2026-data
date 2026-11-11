#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, c_, s_;
	cin >> c >> s >> c_ >> s_;
	if(c != c_){
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(s[0] != s_[0] || s[1] != s_[1]){
		cout << "000";
		return 0;
	}
	cout << 1;
	if(!((s[2] <= 'C' && s_[2] <= 'C') || (s[2] >= 'D' && s_[2] >= 'D'))){
		cout << "00";
		return 0;
	}
	cout << 1;
	if((s[2] == 'A' && s_[2] == 'C') || (s[2] == 'C' && s_[2] == 'A')){
		cout << 0;
	}else{
		cout << 1;
	}
	return 0;
}
