#include <bits/stdc++.h>
using namespace std;
string c,c1,c2,c3;
int main(){
	freopen("trvel.in","r",stdin);
	freopen("trvel.out","w",stdout);
	cin>>c>>c1>>c2>>c3;
	if(c==c2){
		cout<<1;
	}else cout<<0;
	if(c==c2&&c1[0]==c3[0]&&c1[1]==c3[1]){
		cout<<1;
	}else cout<<0;
	if(c==c2&&c1[0]==c3[0]&&c1[1]==c3[1]&&(c1[2]=='A'||c1[2]=='C'||c1[2]=='B')&&(c3[2]=='A'||c3[2]=='C'||c3[2]=='B')||(c1[2]=='D'||c1[2]=='F')&&(c3[2]=='D'||c3[2]=='F')){
		cout<<1;
	}else cout<<0;
	if(c==c2&&c1[0]==c3[0]&&c1[1]==c3[1]&&((c1[2]=='A'&&c3[2]=='B')||(c1[2]=='B'&&c3[2]=='A')||(c1[2]=='B'&&c3[2]=='C')||(c1[2]=='C'&&c3[2]=='B')||(c1[2]=='D'&&c3[2]=='F')||(c1[2]=='F'&&c3[2]=='D'))){
		cout<<1;
	}else cout<<0;
} 


