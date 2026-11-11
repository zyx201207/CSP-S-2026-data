#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1 , s1;
	cin >> c1 >> s1;
	string c2 , s2;
	cin >> c2 >> s2;
	bool f1 = 0;
	if(c1 == c2) f1 = 1;
	else{
		f1 = 0;
		cout << "0000" << '\n';
		return 0;
	}
	bool f2 = 1;
	if(!f1) f2 = false;
	else{
		for(int i = 0 ; i < 2 ; i ++){
			if(s1[i] != s2[i]){
				f2 = false;
				break;
			}
		}
	}
	bool f3 = false;
	if(!f2) f3 = false;
	else{
		char d1 = s1[2] , d2 = s2[2];
		if(d1 == 'A' || d1 == 'B' || d1 == 'C'){
			if(d2 == 'A' || d2 == 'B' || d2 == 'C') f3 = 1;
		}
		if(d1 == 'D' || d1 == 'F'){
			if(d2 == 'D' || d2 == 'F') f3 = 1;
		}
	}
	bool f4 = false;
	if(!f3) f4 = false;
	else{
		char d1 = s1[2] , d2 = s2[2];
		if(d1 == 'A' && d2 == 'B') f4 = 1;
		else if(d1 == 'B' && (d2 == 'A' || d2 == 'B')) f4 = 1;
		else if(d1 == 'C' && d2 == 'B') f4 = 1;
		else if(d1 == 'D' && d2 == 'F') f4 = 1;
		else if(d1 == 'F' && d2 == 'D') f4 = 1;
	}
	cout << f1 << f2 << f3 << f4 << '\n';
	return 0;
}
