#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n;
	cin >> n;
	
	char s[105];
	cin >> s;
	
	int m;
	cin >> m;
	
	char z[105];
	cin >> z;
	
	if(n == m){
		cout << "1"; 
	}
	if(n != m){
		cout << "0000";
		return 0;
 	}
	if(s[0] == s[0] && s[1] == s[1]){
		cout << "1";
	}
	if(s[0] != s[0] || s[1] != s[1]){
		cout << "000";
		return 0;
	}
	if(s[2] == 'D' || s[2] == 'F'){
		if(z[2] == 'D' || z[2] == 'F'){
			cout << "11";
			return 0;
		}
	}
	else if(s[2] == 'A' || s[2] == 'B' || s[2] == 'C'){
		if(z[2] == 'A' || z[2] == 'B' || z[2] == 'C'){
			cout << "1";
		}
	}
	else{
		cout << "00";
		return 0;
	}
	if(s[2] == 'A' || s[2] == 'B'){
		if(z[2] == 'A' || z[2] == 'B'){
			cout << "1";
			return 0;
		}
	}
	if(s[2] == 'B' || s[2] == 'C'){
		if(z[2] == 'B' || z[2] == 'C'){
			cout << "1";
			return 0;
		}
	}
	if(s[2] == 'C' || s[2] == 'D'){
		if(z[2] == 'C' || z[2] == 'D'){
			cout << "0";
			return 0;
		}
	}
		cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
