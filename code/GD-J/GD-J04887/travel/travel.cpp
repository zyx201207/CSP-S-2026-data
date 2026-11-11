#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int num1,num2;
	string a,b;
	cin >> num1 >> a >> num2 >> b;
	
	if(num1 == num2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	int c1 = (a[0] - '0') * 10 + (a[1] - '0');
	int c2 = (b[0] - '0') * 10 + (b[1] - '0');
	if(c1 == c2) cout << '1';
	else {
		cout << "000";
		return 0;
	}
	char s1 = a[2];
	char s2 = b[2];
	if((s1 == 'F' && s2 == 'D') || (s2 == 'F' && s1 == 'D')){
		cout << "11";
	}
	if(s1 <= 'C' && s2 <= 'C'){
		cout << '1'; 
		if(abs(s1 - s2 ) == 1) cout << '1';
		else cout << '0';
	}else cout << "00";
	return 0;
} 
