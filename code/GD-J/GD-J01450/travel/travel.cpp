#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c2 != c1) cout<<"0000";
	else {
		if(s1[0] != s2[0] || s1[1] != s2[1]) cout<<"1000";
		else{
			char a = s1[2],b = s2[2];
			if((a=='F'&&b=='D')||(a=='D'&&b=='F') ||(a=='A'&&b=='B')||(a=='B'&&b=='C')||(b=='A'&&a=='B')||(a=='B'&&b=='C')){
				cout<<"1111";
			}
			else if((a=='A'&&b=='C')||(b=='A'&&a=='C')) cout<<"1110";
			else cout<<"1100";
		}
	}
	return 0; 
}
