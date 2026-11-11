#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2){
		cout << "1";
	} else {
		cout << "0";
	}
	
	cout << "10";
		
	char a = 'A', b = 'B', c = 'C', d = 'D', f = 'F';
	if (s1 == a && s2 == b){
		cout << "1";
	} else if (s1 == b && s2 == c){
		cout << "1";
	} else if (s1 == d && s2 == f){
		cout << "1";
	} else if (s1 == a && s2 == c){
		cout << "0";
	} else if (s1 == a && s2 == d){
		cout << "0";
	} else if (s1 == a && s2 == f){
		cout << "0";
	} else if (s1 == b && s2 == d){
		cout << "0";
	} else if (s1 == b && s2 == f){
		cout << "0";
	} else if (s1 == c && s2 == f){
		cout << "0";
	} else {
		cout << "0";
	}
	
	return 0;
}
