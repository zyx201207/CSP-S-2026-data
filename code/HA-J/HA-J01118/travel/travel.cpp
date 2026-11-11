#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a1=0,a2=0,a3=0,a4=0;
	int c1,c2,a,b;
	bool c=1;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
	}else{
		c=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c!=0){
		a2=1;
	}else{
		c=0;
	}
	
	if((s1[2]=='D'||s1[2]=='F'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s2[2]=='D'||s2[2]=='F'&&s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&c!=0){
		c=0;
	}
	else if(c==1){
		a3=1;
		if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')){
			a4=0;
		}else{
			a4=1;
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
