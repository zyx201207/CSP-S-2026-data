#include <bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2,e1,e2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = (s1[0] - '0') * 10 + s1[1] - '0';
	p2 = (s2[0] - '0') * 10 + s2[1] - '0';
	e1 = s1[2] < 'D' ? 0 : 1;
	e2 = s2[2] < 'D' ? 0 : 1;
	if(c1 == c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(c1 == c2 && p1 == p2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(c1 == c2 && p1 == p2 && e1 == e2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(e1 == e2 && c1 == c2 && p1 == p2 && abs(s1[2] - s2[2]) == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}

