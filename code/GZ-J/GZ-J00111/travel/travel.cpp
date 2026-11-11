//GZ-J00111 凯里学院附属中学 尹宥嘉
#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int s1n = int(s1[0] - '0') * 10 + int(s1[1] - '0'),s2n = int(s2[0] - '0') * 10 + int(s2[1] - '0');
	char s1s = s1[2],s2s = s2[2];
	if(c1 != c1)
	    cout << "0000";
	else{
		if(s1n != s2n){
			cout << "1000";
		}
		else{
			bool a = (s1s == 'A' || s1s == 'B' || s1s == 'C')&&(s2s == 'D' || s2s == 'F');
			bool b = (s2s == 'A' || s2s == 'B' || s2s == 'C')&&(s1s == 'D' || s1s == 'F');
			if(a || b){
				cout << "1100";
			}
			else{
				if((s1s == 'D' && s2s == 'F')||(s2s == 'D' && s1s == 'F')){
					cout << "1111";
				}
				else if((s1s == 'A' && s2s == 'B')||(s2s == 'A' && s1s == 'B')){
					cout << "1111";
				}
				else if((s1s == 'B' && s2s == 'C')||(s2s == 'B' && s1s == 'C')){
					cout << "1111";
				}
				else{
					cout << "1110";
				}
			}
		}
	}
}
