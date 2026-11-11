#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2,ans;
	cin >>c1>>s1>>c2>>s2;
	
	if (c1 == c2){
		ans += "1";
	}
	else {
		ans += "0";
	}
	
	string a,b;
	a += s1[0];
	a += s1[1];
	b += s2[0];
	b += s2[1];
	if (a == b && ans[0] == '1'){
		ans += "1";
	}
	else {
		ans += "0";
	}
	
	char m = s1[2],n = s2[2];
	int m1 = 0,n1 = 0;
	char arr_up[2] = {'D','F'};
	for (int i = 0;i < 2;i++){
		if (m == arr_up[i]){
			m1 = 1;
		}
		if (n == arr_up[i]){
			m1 = 1;
		}
	}
	if (m1 == n1 && ans[1] == '1'){
		ans += "1";
	}
	else {
		ans += "0";
	}
	
	char x = s1[2],y = s2[2];
	if (m1 == 1 && ans[2] == '1'){
		ans += "1";
	}
	else if(ans[2] == '1' && (x == 'B' || y == 'B')){
		ans += "1";
	}
	else{
		ans += "0";
	}
	
	cout <<ans;
	
	return 0;
}

