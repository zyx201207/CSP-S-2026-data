#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f(char a,char b,char x,char y){
	return ((a==x&&b==y) || (a==y&&b==x));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			char d1 = s1[2],d2 = s2[2];
			if ((d1>='D'&&d2<='C') || (d1<='C'&&d2>='D')){
				cout << "00";
			}
			else{
				cout << 1;
				if (f(d1,d2,'D','F') || f(d1,d2,'B','C') || f(d1,d2,'A','B')){
					cout << 1;
				}
				else cout << 0;
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
