#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int main() {
	freopen(travel.in,'r', stdin);
	freopen(travel.out,'w', stdout);
	
	cin >> c1>>s1>>c2>>s2 ;
	if(c1!=c2) cout <<"0000";
	else if(s1[0,1]!=s2[0,1]) cout <<"1000";

    else if(s1[2]+s2[2]==202) cout<<"1111";
    else if(s1[2]*2 == s2[2] + s1[2]-1 && s1[2]!=99) cout<<"1111";
    else if(s2[2]*2 == s2[2] + s1[2]-1 && s2[2]!=99) cout<<"1111";
    else if(s1[2]+s2[2]<197) cout<<"1110";
    else if(s1[2]==99 && s2[2]==98) cout<<"1110";
    else if(s1[2]==98 && s2[2]==99) cout<<"1110";
    else cout<<1100;
	

	return 0;
} 

