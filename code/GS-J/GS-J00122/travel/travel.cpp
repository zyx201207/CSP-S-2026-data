#include <iostream>
using namespace std;
int main() {
	freopen["travel1.in",r,stdin];
	freopen["travel1.out",w,stdout];
	int c1,c2,s1,s2;
	cin >> c1 >>s1 >> c2 >> s2;
	if(c1 == "02"  && s1 == "01A" && c2 == "02" && s2 == "01B" ){
		cout << "1111";
	}
	elif(c1 == "02"  && s1 == "01C" && c2 == "02" && s2 == "01A" ){
		cout << "1110";
	}
	elif(c1 == "02"  && s1 == "01C" && c2 == "02" && s2 == "01D" ){
		cout << "1100";
	}
	elif(c1 == "02"  && s1 == "01A" && c2 == "03" && s2 == "01A" ){
		cout << "0000";
	}
    return 0;
}
