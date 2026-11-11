#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1=02,c2=03;
	string s1="01B",s2="01A";
	int q1=0,q2=0,q3=0,q4=0;
	if(c1==c2 && c1!=1 && c1 != 16)q1=1;//q1
	if(q1==1&& s1[0] == s2[0] && s1[1]==s2[1])q2=1;//q2
	if(q2==1){
		if(s1[2]!='C'&&s2[2]!='D'){
			if(s1[2]!='D'&&s2[2]!='C'){
				if(s1[2]==s2[2]+1)q3=1;
				else if (s1[2]==s2[2]-1)q3=1;
			}
		}
	}
	if(q3==1){
		if(s1[2]=='A' && s2[2]=='B')q4=1;
		else if (s1[2]=='B' && s2[2]=='A')q4=1;
		else if (s1[2]=='B' && s2[2]=='C')q4=1;
		else if (s1[2]=='C' && s2[2]=='B')q4=1;
		else if (s1[2]=='D' && s2[2]=='F')q4=1;
		else if (s1[2]=='F' && s2[2]=='D')q4=1;
	}
	cout << q1 << q2 << q3 << q4;
    return 0;
}
