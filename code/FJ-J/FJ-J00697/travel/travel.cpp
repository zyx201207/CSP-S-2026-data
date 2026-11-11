#include<bits/stdc++.h>
using namespace std;
char cs[5];
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cs[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cs[1]='1';
			if(s1[2]<='C'&&s2[2]<='C'){
				cs[2]='1';
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					cs[3]='1';
				}else{
					cs[3]='0';
				}
			}else if(s1[2]>='D'&&s2[2]>='D'){
				cs[2]='1';cs[3]='1';
			}else{
				cs[2]='0';cs[3]='0';
			}
		}else{
			cs[1]='0';cs[2]='0';cs[3]='0';
		}
	}else{
		cs[0]='0';cs[1]='0';cs[2]='0';cs[3]='0';
	}
	cout<<cs;
	return 0;
} 
