#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f1 = 0,f2 = 0,f3 = 0,f4 = 0;
	string r1 = s1.substr(0,2),r2 = s2.substr(0,2);
	char k1 = s1[2],k2 = s2[2];
	if(c1 == c2){
		f1 = 1;
	}
	if ((f1 == 1) && (r1 == r2)){
		f2 = 1;
	}
	if ((f2 == 1) && ((k1 <= 'C' && k2 <= 'C') || (k1 >= 'D' && k2 >= 'D'))){
		f3 = 1;
	}
	if ((f3 == 1) && (abs(k1 - k2) == 1)){
		f4 = 1;
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
