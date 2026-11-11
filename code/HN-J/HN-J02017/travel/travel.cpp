#include<bits/stdc++.h>
using namespace std;

bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c2,s2;
	cin>>c>>s>>c2>>s2;
	string j="",j2="";
	j+=s[0];
	j+=s[1];
	j2+=s2[0];
	j2+=s2[1];
	char i=s[2],i2=s2[2];
	if(c==c2){
		f1=1;
		if(j==j2)f2=1;
		bool sam=(i=='A'||i=='B'||i=='C');
		bool sam1=(i2=='A'||i2=='B'||i2=='C');
		if(sam==sam1&&j==j2){
			f3=1;
			if(abs((int)i-i2)==1)f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
