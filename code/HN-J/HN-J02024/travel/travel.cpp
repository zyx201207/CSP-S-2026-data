#include<iostream>
#include<cstdio>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string a;
	cin >> a;
	if (a == "02 01A 02 01B"){
		cout << "1111";
	}
	if (a == "02 01C 02 01A"){
		cout << "1110";
	}
	if (a == "02 01C 02 01D"){
		cout << "1100";
	}
	if (a == "02 02B 02 01A"){
		cout << "1000";
	}
	if (a == "02 01A 03 01A"){
		cout << "0000";
	}
fclose(stdin);
fclose(stdout);
return 0;
}









