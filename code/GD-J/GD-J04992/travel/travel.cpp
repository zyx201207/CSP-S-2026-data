#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int q,w,e,r,a,s;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << 0;
	}
	q = s1[0];
	w = s1[1];
	e = s2[0];
	r = s2[1];
	if(c1 == c2){
		if(int(q) + int(w) == int(e) + int(r)){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	a = s1[2];
	s = s2[2];
	if(c1 == c2){
		if(int(q) + int(w) == int(e) + int(r)){
			if((a == 'A' && s == 'B') || (a == 'B' && s == 'C') || (a == 'D' && s == 'F') || (a == 'B' && s == 'A') || (a == 'C' && s == 'B') || (a == 'F' && s == 'D') || (a == 'A' && s == 'C') || (a == 'C' && s == 'A') || (a == 'A' && s == 'C')){
				cout << 1;
			}else{
				cout << 0;
			}
		}
	}else{
		cout << 0;
	}	
	
	if(c1 == c2){
		if(int(q) + int(w) == int(e) + int(r)){
			if((a == 'A' && s == 'B') || (a == 'B' && s == 'C') || (a == 'D' && s == 'F') || (a == 'B' && s == 'A') || (a == 'C' && s == 'B') || (a == 'F' && s == 'D') || (a == 'A' && s == 'C') || (a == 'C' && s == 'A') || (a == 'A' && s == 'C')){
				if((a == 'A' && s == 'B') || (a == 'B' && s == 'C') || (a == 'D' && s == 'F') || (a == 'B' && s == 'A') || (a == 'C' && s == 'B') || (a == 'F' && s == 'D')){
					cout << 1;
				}
			}
		}
	}else{
		cout << 0;
	}
	
	return 0;
} 
