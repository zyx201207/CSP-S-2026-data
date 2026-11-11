#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		string a, b;
		a = s1[0] + s1[1];
		b = s2[0] + s2[1];
		if(a == b){
			cout << "1";
			a = s1[2], b = s2[2];
			if(('A' <= a[0] && a[0] <= 'C' && 'A' <= b[0] && b[0] <= 'C') || ('D' <= a[0] && a[0] <= 'F' && 'D' <= b[0] && b[0] <= 'F')){
				cout << "1";
				int c = int(a[0]) - 'A', d = int(b[0]) - 'A';
				if(abs(c - d) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
