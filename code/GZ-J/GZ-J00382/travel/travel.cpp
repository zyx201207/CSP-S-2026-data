//GZ-J00382;山水中学;史睿琦//
#include <iostream>;
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin >> c1,s1,c2,s2;
	int n = 0;
	if(c1 == c2){
		n += 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			n += 10;
			if(s1[2],s2[2] == "A,B" && s1[2],s2[2] == "B,C" && s1[2],s2[2] == "D,F" && s1[2],s2[2] == "A,C" && s1[2],s2[2] == "A,D" && s1[2],s2[2] == "A,F" && s1[2],s2[2] == "B,D" && s1[2],s2[2] == "B,F" && s1[2],s2[2] == "C,D" && s1[2],s2[2] == "C,F"){
				n += 100;
				if(s1[2],s2[2] == A,B && s1[2],s2[2] == B,C && s1[2],s2[2] == D,F){
					n += 1000;
				}else{
					n += 0;
				}
			}else{
				n += 0;
			}
		}else{
			n += 0;
		}
	}else{
		n += 0;
	}
	cout << n;
	return 0;
}
