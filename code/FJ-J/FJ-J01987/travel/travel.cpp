#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=false,b=false,c=false;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	 cout<<'1';  
	 a=true;
	}else cout<<'0';
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&a==true){
		b=true;
	    cout<<'1';
	}else cout<<'0';
	if(b==true&&s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		cout<<'1';
		c=true;
	}else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'&&b==true){
		cout<<'1';
		c=true;
	}else{
		cout<<'0';
	}
	if(s1[2]=='D'&&s2[2]=='C'||c==false) cout<<'0';
	else if(s2[2]=='D'&&s1[2]=='C') cout<<'0';
	else if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C') cout<<'0';
	else cout<<'1';
	return 0;
}
