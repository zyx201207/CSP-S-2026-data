#include<bits/stdc++.h>
using namespace std;
int ca,cb;
string ans,sa,sb;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb)cout<<"0000";
	else{
		int a=(sa[0]-48)*10+(sa[1]-48);
		int b=(sb[0]-48)*10+(sb[1]-48);
		if(a!=b)cout<<"1000";
		else{
			if(((sa[2]=='D'||sa[2]=='F')&&(sb[2]=='A'||sb[2]=='B'&&sb[2]=='C'))||((sb[2]=='D'||sb[2]=='F')&&(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'))){
				cout<<"1100";
			}else{
				if(sa[2]=='A'&&sb[2]!='B')cout<<"1110";
				else if(sa[2]=='B'&&sb[2]!='A'&&sb[2]!='C')cout<<"1110";
				else if(sa[2]=='C'&&sb[2]!='B')cout<<"1110";
				else if(sa[2]=='D'&&sb[2]!='F')cout<<"1110";
				else if(sa[2]=='F'&&sb[2]!='D')cout<<"1110";
				else cout<<"1111";
			}
		}
	} 
	return 0;
}
