#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		int flag = 1;
		for(int i = 0;i < 2;i++){
			if(s1[i]!=s2[i]){
				flag = 0;
			}
		}
		if(!flag){
			cout << "000";
			return 0;
		}
		else{
			cout << 1;
			if((s1[2]<='C'&&s2[2]<='C')){
				cout << 1;
				if(s1[2] == 'B'||s2[2] == 'B'){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else if((s1[2]>'C'&&s2[2]>'C')){
				cout << "11";
				return 0;
			}
			else{
				cout << "00";
				return 0;
			}
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
}
