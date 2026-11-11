//GZ-J00548   遵义四中 王睿博 
#include <bits/stdc++.h>
using namespace std;

int x , y;
string s1 , s2 , a , b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s1 >> b >> s2;
	x = (s1[0] - '0') * 10 + (s1[1] - '0');
	y = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(a != b){
		cout << "0000";
	}else if(x != y){
		cout << "1000";
	}else if(s1[2] <= 'C' && s2[2] > 'C' || s1[2] >= 'D' && s2[2] < 'D'){
		cout << "1100";
	}else if(s1[2] == 'A' && s2[2] == 'C' || s2[2] == 'A' && s1[2] == 'C'){
		cout << "1110";
	}else{
		cout << "1111";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

