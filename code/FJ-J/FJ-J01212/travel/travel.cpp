#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,da;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	for(int i=0;i<c1.size();i++){
		a*=10;
		a+=c1[i]-'0';
	}
	for(int i=0;i<c2.size();i++){
		b*=10;
		b+=c2[i]-'0';
	}
	if(a==b){
		da[0]='1';
		a=0,b=0;
	char c,d;
	for(int i=0;i<s1.size();i++){
		if(i==s1.size()-1){
			c=s1[i];
			break;
		}
		a*=10;
		a+=s1[i]-'0';
	}
	for(int i=0;i<s2.size();i++){
		if(i==s2.size()-1){
			d=s2[i];
			break;
		}
		b*=10;
		b+=s2[i]-'0';
	}
	if(a==b){
		da[1]='1';
		if(c<='C' and d<='C'){
			da[2]='1';
			int x,y;
			x=c-'0';
			y=d-'0';
			if(abs(x-y)==1){
				da[3]='1';
			}else{
				da[3]='0';
			}
		}else if(c>'C' and d>'C'){
			da[2]='1';
			int x,y;
			x=c-'0';
			y=d-'0';
			if(abs(x-y)==1){
				da[3]='1';
			}else{
				da[3]='0';
			}
		}else{
			da[2]='0';
			da[3]='0';
		}
	}else{
		da[1]='0';
		da[2]='0';
		da[3]='0';
	}
	
	}else{
		da[0]='0';
		da[1]='0';
		da[2]='0';
		da[3]='0';
	}
	for(int i=0;i<=3;i++){
		cout<<da[i];
	}
	
	
	return 0;
} 
