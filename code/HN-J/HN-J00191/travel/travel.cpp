#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>s1>>s2>>s3>>s4;
	int a=0,b=0,c=0,d=0;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		a=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			b=1;
			if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'){
				c=1;
				if(abs(int(s2[2])-int(s4[2]))==1) d=1;
			}else if(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F'){
				c=d=1;
			}
		}	
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
