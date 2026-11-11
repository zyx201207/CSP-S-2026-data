#include <bits/stdc++.h> 
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2&&s1!="01"&&s2!="01"&&s1!="16"&&s2!="16")cout<<1;
	else{
		cout<<0000;
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<1;
	else{
		cout<<000;
		return 0;
	}
	if(c1[1]!=c2[1]||((c1[2]=='C'&&c2[2]=='D')||(c1[2]=='D'&&c2[2]=='C'))){
		cout<<00;
		return 0;
	}
	else cout<<1;
	if(abs(c1[2]-c2[2])==1)cout<<1;
	else cout<<0;
	return 0; 
} 
