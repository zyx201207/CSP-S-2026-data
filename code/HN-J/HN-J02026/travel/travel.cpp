#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	int n1 = (s1[0]-'0')*10+(s1[1]-'0');
	int n2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(n1 != n2){
		cout << "1000";
		return 0;
	}
	char x1 = s1[2], x2 = s2[2];
	if(x1 == 'D' || x1 == 'F'){
		if(x2 != 'D' && x2 != 'F'){
			cout << "1100";
			return 0;
		}
	}else{
		if(x2 == 'D' || x2 == 'F'){
			cout << "1100";
			return 0;
		}
	}
	if(abs((x1-'A')-(x2-'A')) == 1 || (x1=='D' && x2=='F') || (x1=='F' && x2=='D')){
		cout << "1111";
		return 0;
	}
	cout << "1110";
	return 0;
}
