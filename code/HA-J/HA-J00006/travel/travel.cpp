#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b;
	string s1,s2;
	bool m=1;
	cin>>a>>s1>>b>>s2;
	if(a==b) cout<<"1";
	else{
		cout<<"0";
		m=0;
	} 
	if(s1[0]==s2[0] && s1[1]==s2[1] && m) cout<<"1";
	else{
		cout<<"0";
		m=0;
	} 
	if(s1[2]-'A'<=2 && s2[2]-'A'<=2 && m) cout<<"1";
	else{
		cout<<"0";
		m=0;
	}
	if((s1[2]+1==s2[2] || s2[2]+1==s1[2]) && m) cout<<"1";
	else{
		cout<<"0";
	}
		
	
	
	
	
	
	return 0;
}
