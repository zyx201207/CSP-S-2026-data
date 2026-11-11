#include <iostream>
using namespace std;
void check(string astr,string bstr){
	cout << "1";
	if( astr[0]==bstr[0] && astr[1]==bstr[1] ){
		cout << "1";
	}else{
		cout << "000";
		return;
	}if( (astr[2]=='D'||astr[2]=='F') &&bstr[2] <= 'C'
	|| (bstr[2]=='D'|| bstr[2]=='F')  &&astr[2] <= 'C'){
		cout << "00";
		return;
	}else{
		cout << "1";
	}if(astr[2]=='D'|| bstr[2]=='D'	|| astr[2]=='B'||bstr[2]=='B'){
		cout << "1";
	}else{
		cout << "0";
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string astr,bstr;
	cin >> a >> astr >> b >> bstr;
	if(a!=b){
		cout << "0000";
	}else{
		check(astr,bstr);
	}
	return 0;
}
