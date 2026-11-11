#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
	}else if((s1[2] != s2[2]) || (s1[1] != s2[1])){
		cout << "1000";
	}else if((s1[3] == 'C' && s2[3] == 'D') or (s1[3] == 'D' && s2[3] == 'C')){
		cout << "1100";
	}else if(s1[3] - s2[3] > 1){
		cout << "1110";
	}else{
		cout << "1111";
	}
	
	return 0;
}
