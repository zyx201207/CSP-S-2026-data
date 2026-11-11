#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,se,ser,ssan;
	cin >>s>>se>>ser>>ssan;
	if(s==ser){
		cout << "1";
		if(se[0]==ssan[0]&&se[1]==ssan[1]){
			cout << "1";
			if(se[3]<='C'&&ssan[3]<='C' || se[3]>'C'&&ssan[3]>'C'){
				cout << "1";
				if(se[3]+1==ssan[3]||se[3]-1==ssan[3])cout << "1";
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	return 0;
}
