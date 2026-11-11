#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
	if((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')){
		return true;
	}else if((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) return true;
	else return false;
}bool fun(char x,char y){
	if(x == 'A' && y == 'B') return true;
	if(x == 'B' && y == 'A') return true;
	if(x == 'B' && y == 'C') return true;
	if(x == 'C' && y == 'B') return true;
	if(x == 'D' && y == 'F') return true;
	if(x == 'F' && y == 'D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1[0] == s2[0] && s1[1] == s2[1] && check(s1[2], s2[2])) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1[0] == s2[0] && s1[1] == s2[1] && check(s1[2], s2[2]) && fun(s1[2],s2[2])) cout << 1;
	else  cout << 0;
	return 0;
}
