#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;	
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<1;
			if(s1[2]=='D'&&s2[2]=='F') cout<<11;
			else if((s1[2]=='D'||s1[2]=='F')||(s2[2]=='F'||s2[2]=='D')){
				cout<<0<<0;
			}
			else if((s1[2]=='C'||s1[2]=='D')&&(s2[2])=='C'||s2[2]=='D') cout<<0<<0;
			else {
				cout<<1;
				char a=char(s1[2]);
				char b=char(s2[2]);
				
				if(abs(a-b)==1) cout<<1;
				else cout<<0;
			}
		}
		else cout<<0<<0<<0;
   }
	else cout<<0<<0<<0<<0;
	return 0;
	}
