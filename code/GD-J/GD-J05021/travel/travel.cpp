#include <iostream>
#include <string>
using namespace std;
string n,m,s,ss;
int func(char a,char b){
	if((a=='D'&&b=='F')||(a=='F'&&b=='D'))return 2;
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B'))return 2;
	if((a=='A'&&b=='C')||(a=='C'&&b=='A'))return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> s >> m >> ss;
	if(n==m){
		if(s[0]==ss[0]&&s[1]==ss[1]){
			if(func(s[2],ss[2])==1)cout << "1110";
			else if(func(s[2],ss[2])==2)cout << "1111";
			else if(func(s[2],ss[2])==0)cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
} 
