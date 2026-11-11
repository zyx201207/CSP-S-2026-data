#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
	if((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')){
		return true;		
	}
	if((x == 'D' || x == 'E') && (y == 'D' || y == 'E')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans;
	if(c1 == c2){
		cout << "1";
		int num1 = (s1[0]-'0')*10 + s1[1]-'0';
		int num2 = (s2[0]-'0')*10 + s2[1]-'0';
		//cout << endl << num1 << ' ' << num2 << endl;
		char x = s1[2];
		char y = s2[2];
		if(num1 == num2){
			cout << "1";
			if(check(x,y)){
				cout << "1";
				if(abs(x-y) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
