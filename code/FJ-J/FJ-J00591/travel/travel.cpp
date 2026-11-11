#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
	}else{
		a1=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a1==1){
		a2=1;
	}else{
		a2=0;
	}
	if(a2==0){
		a3=0;
	}else if(s1[2]=='D'||s2[2]=='D'){
		if(s1[2]=='E'||s2[2]=='E'){
			a3=1;
		}else{
			a3=0;
		}
	}else{
		if(s1[2]!='D'&&s2[2]!='D'&&s1[2]!='E'&&s2[2]!='E'){
			a3=1;
		}else{
			a3=0;
		}
	}
	if(a3==0){
		a4=0;
	}if(s1[2]-'A'-1==s2[2]-'A'||s2[2]-'A'-1==s1[2]-'A'){
		a4=1;
	}else{
		a4=0;
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
