#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
string c1;
string c2;
string s1;
string s2;
cin>>c1>>s1>>c2>>s2;


	if(c1==c2){
		int a=1;
	}
	else{
		int a=0;
	}	
 int n=s1.size();
 int m=s2.size();
 
 int a[n];
 int b[m];
	if(a[2]=b[2]&&c1==c2){
		int b=1;
	}
	else{
		int b=0;
	}	
	
	if((a[3]>'A'&&a[3]<'C')&&(b[3]>'A'&&b[3]<'C')){
		int c=1;
	}
	else{
		int c=0;
	}
	if((a[3]>'A'&&a[3]<'C')||(b[3]>'A'&&b[3]<'C')){
		int c=0;
	}
	else{
		int c=0;
	}
cout<<a<<b<<c;
		return 0;
}
