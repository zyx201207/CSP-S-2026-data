#include <bits/stdc++.h>
using namespace std;
bool pd1(char a, char b){
	if(a == 'A' || a == 'B' ||a == 'C'){
		if(b == 'A' || b == 'B' ||b == 'C') return true;
	}else if(a == 'D' || a == 'F'){
		if(b == 'D' || b == 'F') return true;
	}
	return false;
}
bool pd2(char a, char b){
	if(a == 'A' || a == 'C'){
		if(b == 'B') return true;
	}else if(a == 'B'){
		if(b == 'A' || b == 'C')return true;
	}else if(a == 'D'){
		if(b == 'F') return true;
	}else if(a == 'F'){
		if(b == 'D') return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2, ans;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		int x = (int)(s1[0] - '0') * 10 + (int)(s1[1] - '0'), y = (int)(s2[0] - '0') * 10 + (int)(s2[1] - '0') ;
		if(x == y){
			if(pd1(s1[2], s2[2])){
				if(pd2(s1[2], s2[2])){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << x << " " << y << '\n'; 
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
