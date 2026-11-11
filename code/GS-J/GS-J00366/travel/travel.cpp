#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
bool fl = false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1[0] == s3[0] && s1[1] == s3[1]){
		fl = true;
		a = 1;
	}
	if(fl == false)
		a = 0;
	if(a == 1 && fl == true && s2[0] == s4[0] && s2[1] == s4[1]){
	    fl = true;
	    b = 1;
	}
	if(fl == false)
		b = 0;
	if(b == 1 && fl == true && (s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] > 'C' && s4[2] >'C')){
		c = 1;
		fl = true; 
	}else{
		c = 0;
		fl = false;
	}
	if(c == 1 && fl == true && abs(s2[2] - s4[2]) == 1 && (s2[2] != 'C' && s4[2] != 'D') && (s2[2] != 'D' && s4[2] != 'C')){
		d = 1;
	}
	else
		d = 0;		
	cout << a << b << c << d;
	return 0;
}
