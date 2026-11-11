#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool d = 0,e = 0,f = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		d = 1;
	}else{
		cout << 0;
	}
	if (d && (s1[0]+s1[1] == s2[0]+s2[1])){
		cout << 1;
		e = 1;
	}else{
		cout << 0;
	}
	if (e && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))){
		cout << 1;
		f = 1;
	}else{
		cout << 0;
	}
	if (f){
		if (s1[2] + 1 == s2[2] - 0 && s1[2] != 'D')cout << 1;
		else {
			if (s1[2] == 'D'){
				cout << 1;
			}else
				cout << 0;
		}
	}else{
		cout << 0; 
	}
}
