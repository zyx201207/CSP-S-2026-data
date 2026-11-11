#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int get_num(string a) {
	return (a[0]-'0')*10 + a[1]-'0';
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	bool f1=false,f2=false,f3=false,f4=false;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		f1 = true;
		int n1=get_num(s1),n2=get_num(s2);
		if(n1 == n2) {
			f2 = true;
			int a=0,b=0;
			char ca=s1[2],cb=s2[2];
			if(ca == 'A' || ca == 'B' || ca == 'C'){
				a++;
			} else {
				b++;
			}
			if(cb == 'A' || cb == 'B' || cb == 'C'){
				a++;
			} else {
				b++;
			}
			if(a == 2 || b == 2) {
				f3 = true;
				if(ca - cb == 1 || ca - cb == -1) {
					f4=true;
				}
			}
		}
	}
	cout << f1<< f2<< f3<< f4;
	return 0;
}

