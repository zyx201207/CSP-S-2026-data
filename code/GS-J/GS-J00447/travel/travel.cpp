#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	vector<string> userRorX_information;
	for (int i = 0; i < 4; i++){
		string user_input;
		cin >> user_input;
		userRorX_information.push_back(user_input);
	}
	if (userRorX_information[0] == userRorX_information[2]){  // check user in once care
		cout << "1";
	}
	else if (userRorX_information[0] != userRorX_information[2]){  // if user not in once care, output 0000 and return 0, application exit
		cout << "0000";
		return 0;
	}
	
	if ((userRorX_information[1][0] == userRorX_information[3][0]) and (userRorX_information[1][1] == userRorX_information[3][1])){  // check the user in once light
		cout << "1";
	}
	
	else if ((userRorX_information[1][0] != userRorX_information[3][0]) or (userRorX_information[1][1] != userRorX_information[3][1])){  // if user not in once light, output other zero and return zero, application exit
		cout << "000";
		return 0;
	}
	char R =  userRorX_information[1][2];
	char X =  userRorX_information[3][2];
	if ((R + 1) ==X || (R-1) == X){
		if ((R + 1) == 68 || (R-1) == 68){
			cout << "00";
			return 0;
		}
		cout << "11";
	}
	if ((R+2) == X || (R-2) == X){
		if (R +2 == 70 || R - 2 == 68){
			cout << "11";
			return 0;
		}
		cout << "00";
	}
}
