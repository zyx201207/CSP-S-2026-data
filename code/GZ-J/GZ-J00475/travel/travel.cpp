//GZ-J00475 遵义市第四中学 卢语涵 
#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << '1';
	}else{
		cout << "0000";
		return 0;
	}
	long long x = 0, y = 0;
	for(int i = 0; i < 2; i++){
		x += int (s1[i] - '0') * 10;
	}
	for(int i = 0; i < 2; i++){
		y += int (s2[i] - '0') * 10;
	}
	x /= 10;
	y /= 10;
	if(x == y){
		cout << '1';
	}else{
		cout << "000";
		return 0;
	}
	
	if((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] < 'D' && s2[2] < 'D')){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	if(int (s1[2] - s2[2]) == 1 || int (s1[2] - s2[2]) == -1){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
}
