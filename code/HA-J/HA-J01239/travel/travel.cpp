#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,rr,x,xx;
	cin>>r>>rr>>x>>xx;
	if(r==x){
		s[1]='1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(rr[0]==xx[0]&&rr[1]==xx[1]){
		s[2]='1';
	}else{
		cout<<"1000";
		return 0;
	}
	if(rr[2]!='D'&&rr[2]!='F'&&xx[2]!='D'&&xx[2]!='F'){
		s[3]='1';
	}else if(rr[2]=='A'&&rr[2]!='B'&&rr[2]=='C'&&xx[2]!='A'&&xx[2]!='B'&&xx[2]!='C'){
		s[3]='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if((rr[2]=='A'&&xx[2]=='B')||(rr[2]=='B'&&xx[2]=='A')||(rr[2]=='B'&&xx[2]=='C')||(rr[2]=='C'&&xx[2]=='B')||(rr[2]=='D'&&xx[2]=='F')||(rr[2]=='F'&&xx[2]=='D')){
		s[4]='1';
	}else{
		cout<<"1110";
		return 0;
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
}
