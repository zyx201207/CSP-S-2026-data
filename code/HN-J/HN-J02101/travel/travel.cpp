#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string s[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	s[0]='0';
	s[1]='0';
	s[2]='0';
	s[3]='0'; 
	if(a==c&&a!="01"&&a!="16"&&c!="01"&&c!="16"){
		s[0]='1';
		if(b[1]==d[1]&&b[0]==d[0]){
			s[1]='1';
		}
		if(b[2]<'G'&&b[2]>'C'&&d[2]<'G'&&d[2]>'C'){
			s[2]='1';
		}else if(b[2]<'D'&&b[2]-0>'A'-1&&d[2]<'D'&&d[2]-0>'A'-1)s[2]='1';
	}
	if(b[2]!=d[2]&&b[2]+0<'D'+0&&b[2]+0>'A'-1){
		if(d[2]+0==b[2]+1||d[2]+0==b[2]-1){
			if(d[2]!='D')s[3]='1';
		}
	}else if(b[2]<'G'&&b[2]>'C'&&d[2]<'G'&&d[2]>'C')s[3]='1';
	for(int i=0;i<4;i++)cout <<s[i];
	return 0;
} 
