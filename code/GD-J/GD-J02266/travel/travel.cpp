#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		string s = s1.substr(0,2);
		string q = s2.substr(0,2);
		if(s == q){
			cout << "1";
			if(s1[2] == 'F' || s1[2] == 'E'){
				if(s2[2] == 'F' || s2[2] == 'E'){
					cout << "11";
					return 0;
				}else{
					cout << "00";
					return 0;
				}
			}else{
				if(s2[2] == 'A' || s2[2] == 'B'||s2[2] == 'C'){
					cout << "1";
					if(abs(s2[2] - s1[2]) == 1){
						cout << "1";
						return 0;
					}else{
						cout << "0";
					}
				}else{
					cout << "00";
					return 0;
				}
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
