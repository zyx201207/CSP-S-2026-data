#include <bits/stdc++.h>
using namespace std;

bool f1,f2,f3,f4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]<='F'))){
				char a=s1[2],b=s2[2];
				if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
