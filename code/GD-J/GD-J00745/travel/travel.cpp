#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s1,s2,s3,s4;
string c1="",c3="";
char c2,c4;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	ll l1=s2.size(),l2=s4.size();
	for(ll i=0;i<l1;i++){
		if(isdigit(s2[i])){
			c1+=s2[i];
		}else{
			c2=s2[i]; 
		}
	}
	for(ll i=0;i<l2;i++){
		if(isdigit(s4[i])){
			c3+=s4[i];
		}else{
			c4=s4[i];
		}
	}
	if(c1==c3){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((c2>='A'&&c2<='C')&&(c4>='A'&&c4<='C')){
		cout<<"1";
	}else if((c2>='D'&&c2<='F')&&(c4>='D'&&c4<='F')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((c2>='A'&&c2<='C')&&(c4>='A'&&c4<='C')){
		if(abs(c2-c4)==1){
			cout<<"1";
		}else{
			cout<<"0"; 
		}
	}else if((c2>='D'&&c2<='F')&&(c4>='D'&&c4<='F')){
		if(abs(c2-c4)==1){
			cout<<"1";
		}else{
			cout<<"0"; 
		}
	}else{
		cout<<"0";
	}
	return 0;
} 
