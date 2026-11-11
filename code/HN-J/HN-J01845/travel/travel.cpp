#include<bits/stdc++.h>
using namespace std;



signed main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	
	bool q = 0, w = 0, e = 0, r = 0;
		
	if(a == c){
		q = 1;
	}
	
	if(b[0] == d[0] && b[1] == d[1]){
		w = 1;
	}
	
	int s1, s2;
	if(b[2] == 'A'){
		s1 = 1;
	}
	else if(b[2] == 'B'){
		s1 = 2;
	}
	else if(b[2] == 'C'){
		s1 = 3;
	}
	else if(b[2] == 'D'){
		s1 = 11;
	}
	else{
		s1 = 12;
	}

	if(d[2] == 'A'){
		s2 = 1;
	}
	else if(d[2] == 'B'){
		s2 = 2;
	}
	else if(d[2] == 'C'){
		s2 = 3;
	}
	else if(d[2] == 'D'){
		s2 = 11;
	}
	else{
		s2 = 12;
	}
	
	if(abs(s1 - s2) <= 2){
		e = 1;
	}
	else{
		e = 0;
	}
	
	if(abs(s1 - s2) == 1){
		r = 1;
	}
	else{
		r = 0;
	}
	
	cout << q << (q & w) << (q & w & e) << (q && w && e && r) << '\n';
	
	
	return 0;
}

