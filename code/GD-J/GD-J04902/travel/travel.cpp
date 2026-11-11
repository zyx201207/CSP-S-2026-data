#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(s1[0]==s2[0] && s1[1] == s2[1]){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	int s1_s = s1[2] - 'A'+1;
	int s2_s = s2[2] - 'A'+1;
	if((s1_s <= 3 && s2_s <= 3) || (s1_s > 3 && s2_s > 3)){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	int num = abs(s1_s - s2_s);
	if(num == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 

