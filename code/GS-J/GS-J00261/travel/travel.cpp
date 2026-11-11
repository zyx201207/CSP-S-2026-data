#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin >> c >> s >> c1 >> s1;
	int gg,hh;
	int a = 0,b = 0,k = 0,d = 0;
	if(c[0] == c1[0]){
		if(c[1] == c1[1]){
			a = 1;
		}
	}
	else{
		a = 0;
	}
	if(a == 1 && s[0] == s1[0]){
		if(s[1] == s1[1]){
			b = 1;
		}
	}
	else{
		b = 0;
	}
	if(b == 1 && s[2] <= 'C' && s[2] >= 'A' && s1[2] >= 'A' && s1[2] <= 'C'){
		k = 1;
	}
	else if(s[2] == 'D'&& s1[2] == 'F'){
		k = 1;
	}
	else{
		k = 0;
	}
	if(k == 1 ){
		if(s[2] < s1[2]){
			gg = (int)s1[2] - (int)s[2];
		}
		else{
			hh = (int)s[2] - (int)s1[2];
		}
		if(gg == 1 || hh == 1){
			d = 1;
		}	
	}
	else{
		d = 0;
	}
	if(a == 1){
		cout << 1;
	}else{
		cout << 0;
	}
	if(b == 1){
		cout << 1;
	}else{
		cout << 0;
	}
	if(k == 1){
		cout << 1;
	}else{
		cout << 0;
	}
	if(d == 1){
		cout << 1;
	}else{
		cout << 0;
	}
	
	return 0;
}
