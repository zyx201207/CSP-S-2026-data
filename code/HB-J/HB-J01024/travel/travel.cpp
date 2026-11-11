#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	s="0000";
	if(s1==s3){
        s[0]='1';
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            s[1]='1';
            bool b1=(s2[2]=='F'&&s4[2]=='D');
            bool b2=(s2[2]=='D'&&s4[2]=='F');
            bool b3=(s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C'));
            bool b4=(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'));
            bool b5=(s2[2]=='C'&&(s4[2]=='B'||s4[2]=='A'));
            if(b1||b2||b3||b4||b5){
                s[2]='1';
                if(s2[2]+1==s4[2]||s2[2]-1==s4[2])
                    s[3]='1';
            }
        }
	}
	cout<<s;
	return 0;
}
