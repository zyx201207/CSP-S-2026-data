#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >>  s2;
	bool f3 = 0;
	if(c1 == c2){
		f3 = 1;
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(s1[0] + s1[1] == s2[0] + s2[1] && f3){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	bool f = 0;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			f = 1;
		}
	} 
	else if(s1[2] == 'D' || s1[2] == 'E'){
		if(s2[2] == 'D' || s2[2] == 'E'){
			f = 1;
		}
	}
	bool f2 = 0;
	if(s1[0] + s1[1] == s2[0] + s2[1]){
		f2 = 1;
	}
	if(f2 && f && f3){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	f = 0;
	if((s1[2] == 'A' && s2[2] == 'B')|| (s1[2] == 'B' && s2[2] == 'C')|| (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')){
		f = 1;
	}
	else if((s1[2] == 'D' && s2[2] == 'E') || (s1[2] == 'E' && s2[2] == 'D')){
		f = 1;
	}
	if(f && f2 && f3){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 
