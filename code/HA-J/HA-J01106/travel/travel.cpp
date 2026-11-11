#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int hh[5],jj[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	hh[0] = s1[0];
	hh[1] = s1[1];
	jj[0] = s2[0];
	jj[1] = s2[1];
	if(hh[0] == jj[0] && hh[1] == jj[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	int dd = s1[2];
	int ff = s2[2];
	if((dd == 'F' && ff == 'D') || (dd == 'D' && ff == 'F')){
		cout << "11";
		return 0;
	}else if(dd != 'F'&& dd != 'D' && ff != 'F' && ff != 'D'){
		cout << "1";
		if(dd == 'B' || ff == 'B'){
			cout << "1";
			return 0;
		}else{
			cout << "0";
			return 0;
		}
	}else{
		cout << "00";
	}
	return 0;
}
