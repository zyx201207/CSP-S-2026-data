#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	string s1="",f1="";
	char s2,f2;
	if(a==d){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<3;i++){
		if(s[i]>=0 && s[i]<=9){
			s1+=s[i];
		}
		if(f[i]>=0 && f[i]<=9){
			f1+=f[i];
		}
		if(s[i]=='A' || s[i]=='B' || s[i]=='C' ||s[i]=='D' || s[i]=='F'){
			s2+=s[i];
		}
		if(f[i]=='A' || f[i]=='B' || f[i]=='C' ||f[i]=='D' || f[i]=='F'){
			
		
			f2+=f[i];
		}
	}
	if(s1==f1){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(s2=='A' && f2=='B'){
		cout<<1<<1;
	}
	else if(s2=='B' && f2=='A'){
		cout<<1<<1;
	}
	else if(s2=='C' && f2=='B'){
		cout<<1<<1;
	}
	else if(s2=='B'&& f2=='C'){
		cout<<1<<1;
	}
	else if(s2=='D' && f2=='F'){
		cout<<1<<1;
	}
	else if(s2=='F' && f2=='D'){
		cout<<1<<1;
	}
	else{
		cout<<0<<0;
	}
	return 0;
}
