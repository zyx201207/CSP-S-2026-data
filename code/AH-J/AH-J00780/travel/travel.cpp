#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	string a,b,c,d;
	a+=s1[0]+s1[1];
	b+=s2[0]+s2[1];
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	c=s1[2];
	d=s2[2];
	if((c>="A"&&c<="C"&&d>="A"&&d<="C")||(c>="D"&&c<="F"&&d>="D"&&d<="F")){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((c=="A"&&d=="B")||(c=="B"&&d=="C")||(c=="B"&&d=="A")||(c=="C"&&d=="B")||(c=="D"&&d=="F")||(c=="F"&&d=="D")){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
