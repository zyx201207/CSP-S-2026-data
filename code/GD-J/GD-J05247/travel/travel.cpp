#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		s[0]='1';
		s[1]='1';
	}
	else{
		s[0]='0';
		s[1]='0';
	}
	for(long long i=0;i<2;i++){
		if(b[i]!=d[i]){
			s[1]='0';
			break;
		}
	}
	if(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C') || ((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')))&&s[1]=='1'&&s[0]=='1'){
		s[2]='1';
	}
	else{
		s[2]='0';
	}
	if((b[2]+1==d[2]||b[2]-1==d[2])&&s[2]=='1'){
		s[3]='1';
	}
	else{
		s[3]='0';
	}
	cout<<s[0]<<s[1]<<s[2]<<s[3];
	return 0;
} 
