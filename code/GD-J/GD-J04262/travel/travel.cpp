#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s,v;int a,b;bool same1=1,same2=1,same3=1;
	cin>>a>>s>>b>>v;
	
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0";
		same1=0;
	}
	if(s[0]==v[0] && s[1]==v[1] && same1==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		same2=0;
	}
	if((v[2]=='C' || s[2]=='C') &&(v[2]=='D' || s[2]=='D') ){
		cout<<"0";
		same3=0;
	}
	else if(same2==1 && same1==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		
	if((s[2]-'A'==v[2]-'A'+1 || s[2]-'A'==v[2]-'A'-1 )&&same3==1&&same1==1&&same2==1){
		cout<<"1";
	}	
	else
		cout<<"0";
		

	return 0;
}
