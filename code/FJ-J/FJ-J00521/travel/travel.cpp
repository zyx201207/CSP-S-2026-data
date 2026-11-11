#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	cout<<(c1==c2)<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	cout<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'));
	cout<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')&&(abs(s1[2]-s2[2])==1));
	
	return 0;
}                
