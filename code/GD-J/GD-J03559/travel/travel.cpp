#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	bool flag1 = false, flag2 = false, flag3 = false;
	cin >> c1 >> s1 >> c2 >> s2;
	int len = s1.size()-1, let = s2.size()-1;
	if(c1 == c2){
		cout << 1;
		if(s1[1] == s2[1] && s1[0] == s2[0]){
			flag1 = true;
			if(s1[len] == 'A' || s1[len] == 'B' || s1[len] == 'C' && s2[let] == 'A' || s2[let] == 'b' || s2[let] == 'C'){
				flag2 = true;
				if(int(s1[len])+1 == int(s2[let]) || int(s1[len])-1 == int(s2[let])) flag3 = true;
			}
			if(s1[len] == 'D' || s1[len] == 'F' && s2[let] == 'D' || s2[let] == 'F'){
				flag2 = true;
				if(int(s1[len])+1 == int(s2[let]) || int(s1[len])-1 == int(s2[let])) flag3 = true;
			}
		} 
	}else cout << 0;
	if(flag1) cout << 1;
	else cout << 0;
	if(flag2) cout << 1;
	else cout << 0;
	if(flag3) cout << 1;
	else cout << 0;
	return 0;
}
