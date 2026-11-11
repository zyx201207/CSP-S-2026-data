#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	string s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<0;
	}
		if((s2[0]==s4[0] && s2[1]==s4[1]) && (s1==s3)){
			cout<<1;
		}else{
			cout<<0;
		}
		if((s2[2]>='A' && s2[2]<='C' ) && (s4[2]>='A' && s4[2]<='C') && (s2[0]==s4[0] && s2[1]==s4[1]) &&(s1==s3)){
			cout<<1;
		}else if((s2[2]=='D' || s2[2]=='F') && (s4[2]=='D' || s4[2]=='F') && (s2[0]==s4[0] && s2[1]==s4[1]) &&(s1==s3)){
			cout<<1;
		}else{
			cout<<0;
		}
		if(((s2[2]+1==s4[2] && s4[2]!='D') || (s2[2]+2==s4[2] && s2[2]=='D')) && (s2[0]==s4[0] && s2[1]==s4[1]) && (s1==s3)){
			cout<<1;
		}else if(((s2[2]-1==s4[2] && s2[2]!='D') || (s2[2]-2==s4[2] && s2[2]=='F') )&& (s2[0]==s4[0] && s2[1]==s4[1]) &&(s1==s3)){
			cout<<1;
		}
		else{
			cout<<0;
		}
	return 0;
}