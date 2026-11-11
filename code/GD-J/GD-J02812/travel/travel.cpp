#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		a=1;
	}
	string s1=r2.substr(0,2);
	string s2=x2.substr(0,2);
	//cout<<s1<<' ' <<s2<<endl;
	if(s1==s2){	
		b=1;
		if(r2[2]<='C'&&x2[2]<='C'){
			c=1;
			if(abs(r2[2]-x2[2])==1){
			d=1;
		    }
		}
		if(r2[2]>'C'&&x2[2]>'C'){
			c=1;
			if(abs(r2[2]-x2[2])==1){
			d=1;
		    }
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
	
} 
