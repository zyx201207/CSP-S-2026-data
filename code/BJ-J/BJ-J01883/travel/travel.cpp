#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> aa >> b >> bb;
	if(a[0] == b[0] && a[1] == b[1])cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(aa[0] == bb[0] && aa[1] == bb[1])cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if(aa[2] < 'D' && bb[2] < 'D' || aa[2] >= 'D' && bb[2] >= 'D'){
		if(abs(aa[2] - bb[2]) == 1)cout << 11;
		else cout << 10;
	}
	else cout << "00";
	return 0;
}
