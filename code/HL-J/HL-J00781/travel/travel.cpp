#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<'1';
	else {
		cout<<"000";
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if(a1>a2){
		char c=a1;
		a1=a2;
		a2=c;
	}
	if(a1=='D') {
		cout<<"11";return 0;
	}
	else if(a1<='C'){
		if(a2>'C'){
			cout<<"00";
			return 0;
		}
		cout<<'1';
		if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')) cout<<'1';
		else cout<<'0';
	}
	return 0;
}
