#include<bits/stdc++.h>
using namespace std;
string s[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	bool ok1=0,ok2=0,ok3=0;
	if(s[0]==s[2])printf("1"),ok1=1;
	else printf("0");
	
	
	if(!ok1)printf("0");
	else{
		string p="";
		p+=s[1][0];
		p+=s[1][1];
		string q="";
		q+=s[3][0];
		q+=s[3][1];
		if(p==q)printf("1"),ok2=1;
		else printf("0");
	}
	
	
	if(!ok1||!ok2)printf("0");
	else{
		char p=s[1][2],q=s[3][2];
		if((p<='C'&&q<='C')||(p>='D'&&q>='D'))
			printf("1"),ok3=1;
		else printf("0");
	}
	
	
	if(!ok1||!ok2||!ok3)printf("0");
	else{
		int p=s[1][2]-'A',q=s[3][2]-'A';
		if((p<=2&&(p==q+1||p==q-1))||p>=3)
			printf("1");
		else printf("0");
	}
}