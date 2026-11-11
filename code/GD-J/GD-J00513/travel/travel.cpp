#include <bits/stdc++.h>
using namespace std;
string cpos,cseat,xpos,xseat;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cpos >> cseat >> xpos >> xseat;
	if (cpos==xpos)
		cout << '1';
	else{
		cout << "0000";
		return 0;
	}
	string crow=cseat.substr(0,2),xrow=xseat.substr(0,2);
	if (crow==xrow)
		cout << '1';
	else{
		cout << "000";
		return 0;
	}
	char ccol=cseat[2],xcol=xseat[2];
	if ((ccol<='C'&&xcol<='C')||(ccol>='D'&&xcol>='D'))
		cout << '1';
	else
		cout << '0';
	if (abs(ccol-xcol)<=1){
		if ((ccol>='C'&&ccol<='D')||(xcol>='C'&&xcol<='D'))
			cout << '0';
		else
			cout << '1';
	}
	else
		cout << '0';
	return 0;
}
