#include<bits/stdc++.h>
using namespace std;
bool clear(int a){
	if(a == 'A' || a == 'B' || a == 'C') return true;
	return false;
}
bool clear2(int b){
	if(b == 'D'||b == 'F') return true;
	return false;
}
bool be(int a,int b){
	if(a == 'A' && b == 'B') return true;
	if(a == 'B' && b == 'A') return true;
	else if(a == 'B' && b == 'C') return true;
	if(a == 'C' && b == 'B') return true;
	return false;
}
bool be1(int a,int b){
	if(a == 'D' && b == 'F') return true;
	if(a == 'F' && b == 'D') return true;
	return false; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(clear(s1[2]) && clear(s2[2])){
				cout << 1;
				if(be(s1[2],s2[2])){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else if(clear2(s1[2]) && clear2(s2[2])){
				cout << 1;
				if(be1(s1[2],s2[2])){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0;
				cout << 0;
			}
		}
		else{
			cout << 0;
			cout << 0;
			cout << 0; 
		}
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	return 0;
}
