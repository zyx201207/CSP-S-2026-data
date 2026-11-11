#include <iostream>
using namespace std;
string c1,c2,s1,s2, d1,d2;
char ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		ans[0] = '1';
	else{
		ans[0] = '0',ans[1]='0',ans[2]='0',ans[3]='0';
		cout << ans[0] << ans[1] << ans[2] << ans[3];
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1])
		ans[1] = '1';
	else{
		ans[1]='0',ans[2]='0',ans[3]='0';
		cout << ans[0] << ans[1] << ans[2] << ans[3];
		return 0;
	}
	
	if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
		ans[2]='1',ans[3]='1';
		cout << ans[0] << ans[1] << ans[2] << ans[3];
		return 0;
	}
	if(s1[2] == 'D' || s2[2] == 'D' || s1[2] == 'F' || s2[2] == 'F'){
		ans[2]='0',ans[3]='0';
		cout << ans[0] << ans[1] << ans[2] << ans[3];
		return 0;
	}
	
	ans[2] = '1'; 
	if(s1[2] == 'A'){
		if(s2[2] == 'B'){
			ans[3]='1';
		}
		else{
			ans[3]='0';
		}
	}
	else if(s1[2] == 'B'){
		if(s2[2] == 'A' || s2[2] == 'C'){
			ans[3]='1';
		}
	}
	else{
		if(s2[2] == 'B'){
			ans[3]='1';
		}
		else{
			ans[3]='0';
		}
	}
	cout << ans[0] << ans[1] << ans[2] << ans[3];
	return 0;
}
