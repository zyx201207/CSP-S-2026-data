#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1) cout<<"0000";
	else{
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<'1';
			char a=a2[2],b=b2[2];
			if(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='F')&&(b>='D'&&b<='F'))){
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(b=='A'&&a=='B')||(b=='B'&&a=='C')||(b=='D'&&a=='F'))cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}
	return 0;
} 
