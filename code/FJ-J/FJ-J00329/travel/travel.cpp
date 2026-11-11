#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {cout <<"0000";
	return 0;
	}
	int a1=(s1[0]-'0')+(s1[1]-'0'),a2=(s2[0]-'0')+(s2[1]-'0');
	if(a1==a2)cout <<"1";
	else {cout <<"000";
	return 0;
	}
	if('A'<=s1[2] && s1[2]<='C'){
		if('A'<=s2[2] && s2[2]<='C'){cout <<"1";
			if(abs(s1[2]-s2[2])==1)cout <<"1";
			else cout <<"0";
		}
		else cout <<"00";
	}
	else if('D'<=s1[2] && s1[2]<='F'){
		if('D'<=s1[2] && s1[2]<='F'){cout <<"1";
		if(abs(s1[2]-s2[2])==2)cout <<"1";
			else cout <<"0";
		}
		else cout <<"00";
	}
	
	return 0;
}
