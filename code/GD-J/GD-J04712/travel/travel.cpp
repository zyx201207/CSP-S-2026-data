#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1 , c2;
	string s1 , s2;
	int c = 2;
	char s1shuzu[10] = {};
	char s2shuzu[10] = {};
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i <= 2; i ++){
		s1shuzu[i + 1] = s1[i];
		s2shuzu[i + 1] = s2[i];
	}
	if(c1 != c2){
		cout << "0000";
	}
	if(c1 == c2){
		cout << "1";
		if(s1shuzu[1] == s2shuzu[1] && s1shuzu[2] == s2shuzu[2]){
			cout << "1";
			c = 0;
			if(s1shuzu[3] == 'A' && s2shuzu[3] == 'B'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'A' && s2shuzu[3] == 'C'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'B' && s2shuzu[3] == 'C'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'B' && s2shuzu[3] == 'A'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'C' && s2shuzu[3] == 'A'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'C' && s2shuzu[3] == 'B'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'E' && s2shuzu[3] == 'F'){
				cout << "1";
				c = 1;
			}
			if(s1shuzu[3] == 'F' && s2shuzu[3] == 'E'){
				cout << "1";
				c = 1;
			}
		}
		else{
			cout << "000";
		}
	}
	if (c == 0){
		cout << "00";
	}
	else if ( c == 1){
		if(s1shuzu[3] - 'A' - (s2shuzu[3] - 'A') == 1 || s1shuzu[3] - 'A' - (s2shuzu[3] - 'A') == -1){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	return 0;
}
