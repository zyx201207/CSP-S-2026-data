#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		for (int i = 0;i < 2;i ++){
			if (s1[i] == s2[i]){
				cout << 1;
			}
			else{
				cout << "000";
				return 0;
			}
		}
		if ((s1[2] == 'D' or s2[2] == 'D') && (s1[2] < 'D' or s2[2] < 'D')){
			cout << "00";
			return 0;
		}
		else{
			cout << 1;
			if (abs(s2[2] - s1[2]) == 1){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
} 
