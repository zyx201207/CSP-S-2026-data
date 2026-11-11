//GZ-J00409 遵义市第四中学 魏云藩 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	ios::sync_with_stdio(false);
	
	string c1 = "",c2 = "",s1 = "",s2 = "";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if (s1[2] < 'D' && s2[2] < 'D'){
				if (s1[2]-s2[2] <= 1 && s1[2]-s2[2] >= -1){
					cout << "11";
				}
				else if (s1[2]-s2[2] <= 2 && s1[2]-s2[2] >= -2){
					cout << "10";
				}
			}
			else if (s1[2]>'C' && s2[2]>'C'){
				cout << "11";
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}

