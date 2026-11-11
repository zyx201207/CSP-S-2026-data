#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	int a,b,c,d;
	cin>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a=1;	
	}else{
		a=0;
	}	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		b=1;	
	}else{
		b=0;	
	}
	if(b=1){
		int e,f;
		if(s1[2]=='D'||s2[2]=='F')	e=1;
		if(s2[2]=='D'||s2[2]=='F')	f=1;
		if(e&&f){
			c=1;
		}else if(e==0&&f==0){
				c=1;	
			}else{
				c=0;
			}
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F')
			d=1;
	}else if(s1[2]=='C'||s1[2]=='B'){
			if(s2[2]=='B'||s2[2]=='C')	d=1;
		}else if(s1[2]=='B'||s1[2]=='A'){
			if(s2[2]=='B'||s2[2]=='A')	d=1;
		}else{
			d=0;
		}
	cout<<a<<b<<c<<d;
	return 0;
}
