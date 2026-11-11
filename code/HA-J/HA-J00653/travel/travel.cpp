#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a==c){
		s+='1';
	}
	else{
		s="0000";
		cout<<s;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		s+='1';
	}else{
		s+="000";
		cout<<s;
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||
	b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||
	b[2]=='C'&&d[2]=='B'||b[2]=='C'&&d[2]=='A'||
	b[2]=='D'&&d[2]=='F'||
	b[2]=='F'&&d[2]=='D'){
		s+='1';
	}else{
		s+="00";
		cout<<s;
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||
	b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		s+='1';
	}else{
		s+='0';
	}
	cout<<s;
	return 0;
}