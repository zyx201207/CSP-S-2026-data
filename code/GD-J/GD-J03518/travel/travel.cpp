#include<bits/stdc++.h>
using namespace std;
string a,b;//a是R的车厢号,b是X的车厢号
string m,n;//m是R的座位号,n是X的座位号
string s;//s用来存答案 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>b>>n;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else s+='1';
	if(m[0]==n[0]&&m[1]==n[1]){
		s+='1';
	}else{
		cout<<s<<"000";
		return 0;
	}
	if(m[2]<='C'&&n[2]<='C'){
		s+='1';
	}else if(m[2]>='D'&&n[2]>='D'){
		s+='1';
	}else{
		cout<<s<<"00";
		return 0;
	}
	if(m[2]=='A'||m[2]=='C'){
		if(n[2]=='B'){
			s+='1';
		}else{
			s+='0';
		}
	}
	if(m[2]=='B'){
		if(n[2]=='C'&&n[2]=='A'){
			s+='1';
		}else{
			s+='0';
		}
	}
	if(m[2]=='D'){
		if(n[2]=='F'){
			s+='1';
		}else{
			s+='0';
		}
	}
	if(m[2]=='F'){
		if(n[2]=='D'){
			s+='1';
		}else{
			s+='0';
		}
	}
	cout<<s;
	return 0;
}
