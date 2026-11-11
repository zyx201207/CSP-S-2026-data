#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
bool fun1(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='A'&&b=='C'||a=='C'&&b=='A'||a=='D'&&b=='F'||a=='F'&&b=='D'){
		return true;
	}else{
		return false;
	}
}
bool fun2(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
		return true;
	}else{
		return false;
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << "1";
			if(fun1(s1[2],s2[2])){
				cout << "1";
				if(fun2(s1[2],s2[2])){
					cout << "1";
				}else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";	
	return 0;
}