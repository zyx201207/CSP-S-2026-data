#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	cin>>c1>>s1>>c2>>s2;
	int l=1;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		l=0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&l==1){
		cout<<1;
	}
	else{
		cout<<0;
		l=0;
	}
	
	if(l==0)cout<<0;
	else if(s1[2]-'A'<=2&&s2[2]-'A'<=2)cout<<1;
	else if(s1[2]-'A'>2&&s1[2]-'A'>2)cout<<1;
	else{
		l==0;
		cout<<0;
	}
	
	if(l==0){
		cout<<0;
	}
	else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C')cout<<1;
		else{
			cout<<0;
			l=0;
		}
	}
	else if(s2[2]=='B'){
		if(s1[2]=='A'||s1[2]=='C')cout<<1;
		else{
			cout<<0;
			l=0;
		}
	}
	else if(s1[2]=='D'){
		if(s2[2]=='F')cout<<1;
		else{
			cout<<0;
			l=0;
		}
	}
	else if(s2[2]=='D'){
		if(s1[2]=='F')cout<<1;
		else{
			cout<<0;
			l=0;
		}
	}
	else{
		cout<<0;
		l=0;
	}
	return 0;
}
