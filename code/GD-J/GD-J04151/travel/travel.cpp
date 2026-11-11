#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>>c2>>s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	
	int value1 = (s1[0]-'0')*10+(s1[1]-'0');
	int value2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(value1 == value2){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
//	cout <<(value1 == value2);
	
	char a = s1[2];
	char b = s2[2];
	if((('A' <= a && a <= 'C')&&('A' <= b&&b <= 'C'))||(('D' <= a && a <= 'F')&&('D' <= b&&b <= 'F'))){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if(abs(a-b) == 1){
		if((a == 'C'&&b == 'D')||(a == 'D'&& b == 'C')){
			cout << "0";
			return 0;
		}
		cout << "1";
	}else{
		if((a == 'F'&&b == 'D')||(a == 'D'&& b == 'F')){
			cout << "1";
			return 0;
		}
		cout << "0";
	}
	return 0;
}
