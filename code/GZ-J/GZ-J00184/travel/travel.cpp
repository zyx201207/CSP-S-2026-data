#include<bits/stdc++.h>
using namespace std;

int main(){
	//GZ-J00184 ×ñÒåËÄÖÐ ÑîÖÇº­ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int a=0,b=0,c=0,d=0;
	if(s1==s3){
		a=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		b=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'){
		c=1;
	}else if(s2[2]>='D'&&s2[2]<='E'&&s4[2]>='D'&&s4[2]<='E'){
		c=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	int r1=(s2[0]-'0')*10+s2[1]-'0',r2=(s4[0]-'0')*10+s4[1]-'0';
	if(abs(r1-r2)==0&&abs(s2[2]-s4[2])==1){
		d=1;
	}else if(abs(r1-r2)==1&&abs(s2[2]-s4[2])==0){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
