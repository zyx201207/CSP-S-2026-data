#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin >> a >> aa >> b >> bb;
	if(a != b){
		cout << "0000";
	}else if(aa[0] != bb[0]||aa[1] != bb[1]){
		cout << "1000";
	}else if((aa[2] <='C'&&bb[2]>'C')||(aa[2] >= 'D'&&bb[2] <= 'C')){
		cout << "1100";
	}else if(abs(aa[2] - bb[2]) > 1){
		cout << "1110";
	}else{
		cout << "1111";
	}
	return 0;
}
