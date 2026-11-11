#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
string ans;
string n;
string m;
string a;
string b;
string y;
string z;
char seat;

void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
	}
	else{
		ans+="0000";//判断第一个数 
	}
	for(ll i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			n+=s1[i];
		}
	}
	for(ll i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			m+=s2[i];
		}
	}
	if(m==n){
		ans+='1';
	}
	else{
		ans+='000';//判断第二个数是几 
	}
	for(ll i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			n+=s1[i];
		}
	}
	for(ll i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			m+=s2[i];
		}
	}
	for(ll i=0;i<s1.size();i++){
		if(isalpha(s1[i])){
			a+=s1[i];
		}
		
	}
	
	
	for(ll i=0;i<s2.size();i++){
		if(isalpha(s2[i])){
			b+=s2[i];
		}
		
	}
	if(m==n){
		ans+='1';
	}
	else{
		ans+='00';
	}
	for(ll i=0;i<s1.size();i++){
		if(isalpha(s1[i])){
			y+=s1[i];
		}
		
	}
	
	
	for(ll i=0;i<s2.size();i++){
		if(isalpha(s2[i])){
			z+=s2[i];
		}
		/*if(s2[i]+'1'==s1[i]||s2[i]-'1'==s1[i]){
			ans+='1';
		} 
		else{
			ans+='0';
		}*/
		
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='C'||s1[2]=='E'&&s2[2]=='D'||s1[2]=='F'&&s2[2]=='E'){
			ans+='1';
		} 
		else{
			ans+='0';
		}

	
	


	 
	
cout<<ans;	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve(); 
	return 0;
}
