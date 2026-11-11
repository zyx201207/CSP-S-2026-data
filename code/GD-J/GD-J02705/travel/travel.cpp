#include<bits/stdc++.h>
using namespace std;
string s1 , s2 , s3 , s4;
int a , b , c , d;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) a = 1;
	if(s2[0] == s4[0] && s2[1] == s4[1] && a == 1) b = 1 , c = 1;
	if((s2[2] == 'A' && s4[2] == 'D') || (s2[2] == 'A' && s4[2] == 'F')) c = 0;
	if((s2[2] == 'B' && s4[2] == 'D') || (s2[2] == 'B' && s4[2] == 'F')) c = 0;
	if((s2[2] == 'C' && s4[2] == 'D') || (s2[2] == 'C' && s4[2] == 'F')) c = 0;
	if((s4[2] == 'A' && s2[2] == 'D') || (s4[2] == 'A' && s2[2] == 'F')) c = 0;
	if((s4[2] == 'B' && s2[2] == 'D') || (s4[2] == 'B' && s2[2] == 'F')) c = 0;
	if((s4[2] == 'C' && s2[2] == 'D') || (s4[2] == 'C' && s2[2] == 'F')) c = 0;
	if(abs(s2[2] - s4[2]) == 1 && c == 1) d = 1;
	//if((s2[2] == 'C' && s4[2] == 'D') || (s2[2] == 'D' && s4[2] == 'C')) d = 0;
	cout << a << b << c << d;
	return 0;
}

