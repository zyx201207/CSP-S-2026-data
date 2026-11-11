#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s, sm, ss, ssm;
	cin >> s >> sm >> ss >> ssm;
	if(s == ss) cout << '1';
	else{
		cout << "0000";
		return 0;
	}
	if(sm[0] == ssm[0] && sm[1]==ssm[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(((sm[2] >='A' && sm[2] <= 'C') && (ssm[2] >='A' && ssm[2] <= 'C')) || ((sm[2] >='D' && sm[2] <= 'F') && (ssm[2] >='D' && ssm[2] <= 'F'))){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	
	if(abs((int)sm[2]-(int)ssm[2]) <= 1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
