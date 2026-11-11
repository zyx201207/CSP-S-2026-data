#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool A[4];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2  >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;//1
	string a;
	a = s1[0];
	a+=s1[1];
	string b;
	b = s2[0];
	b+=s2[1];
//	cout << a << endl << b;
	if(a == b) {
		cout << 1;//2
		char t1 = s1[2];
		char t2 = s2[2];
//		cout << endl <<t1<<' '<<t2<<endl;
		if(t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C') {
			cout << 1;
			if(abs(t1 - t2) == 1) cout << 1;
			else cout << 0;
//			cout << endl<<abs(t1-t2)<<endl;
		} else if(t1 >= 'D' && t1 <= 'F' && t2 >= 'D' && t2 <= 'F') {
			cout << 1 << 1;
		} else cout << 0 << 0; //3,4
	} else cout << 0 << 0 << 0; //2,3,4
	return 0;
}
