#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int f=0;
bool b=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		b=true;
	}else{
		cout<<0;
	}
	
	if(s1[1]==s2[1] && b) cout<<1;
	else cout<<0;
	
	if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C') && b){
		cout<<1;
		f=1;
	}else if((s1[2]=='D' || s1[2]=='F') && (s1[2]=='D' || s1[2]=='F') && b){
		cout<<1;
		f=2;
	}else cout<<0;
	
	if(f==1){
		if(s1[2]-'0'+'1'==s2[2] || s1[2]-'0'+1==s1[2]) cout<<1;
		else cout<<0;
	}else if(f==2){
		if(s1[2]-'0'+'2'==s2[2] || s1[2]-'0'+'2'==s1[2]) cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
