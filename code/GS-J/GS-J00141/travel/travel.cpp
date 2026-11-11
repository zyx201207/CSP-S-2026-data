#include<bits/stdc++.h>
using namespace std;
 
int main(){
	
	freopen("travel.in","t",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		a+=1;
	}
	else{
		a+=0;
	}
	if(s2[1]==c2[1]&&a==1){
		
		b+=1;
	}
	else{
		b+=0;
	}
	if(s2[1]==c2[1]&&a==1&&s2[2]!='C'&&c2[2]!='D'&&c2[2]!='C'&&s2[2]!='D'){
		c+=1;
	}
	else if(s2[2]=='C'&&c2[2]!='D'||s2[2]!='C'&&c2[2]=='D'||s2[2]!='D'&&c2[2]=='C'||s2[2]=='D'&&c2[2]!='C') {
		c+=1;
	}
	else{ 
		c+=0;
	}

	if(c2[2]+1==s2[2]&&a==1&&c2[2]!='C'&&s2[2]!='D'){
		d+=1;
	}
	else {
		d+=0;
	}
	
	cout<<a<<b<<c<<d;
	
	return 0;
}

