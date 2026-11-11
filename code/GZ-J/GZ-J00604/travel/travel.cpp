//GZ-J00604 遵义市新蒲中学 杨子曦
#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f = false;
	string s1,s2,s3,s4,s5;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3){
		int x,y;
		x = (s2[0]-'0')*10+(s2[1]-'0');
		y = (s4[0]-'0')*10+(s4[1]-'0');
		if(x != y){
			cout << "1000";
			return 0;
		}else{
			if(s2[2] >= 'A'&&s2[2] <= 'C'&&s4[2] >= 'A'&&s4[2] <= 'C'){
				f = true;
			}else if(s2[2] >= 'D'&&s2[2] <= 'F'&&s4[2] >= 'D'&&s4[2] <= 'F'){
				f = true;
			}
			if(!f){
				cout << "1100";
				return 0;
			}else{
				if(s2[2] >= 'A'&&s4[2] >= 'A'&&s4[2] <= 'C'&&s2[2] <= 'C'&&abs(int(s2[2]-s4[2])) == 1){
					cout << "1111";
					return 0; 
				}else if(s2[2] >= 'D'&&s4[2] >= 'D'&&s4[2] <= 'F'&&s2[2] <= 'F'){
					cout << "1111";
					return 0;
				}else{
					cout << "1110";
					return 0;
				}
			}
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
} 
