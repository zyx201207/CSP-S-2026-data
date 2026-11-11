#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]!=c2[1]){
		cout<<"0000";
		return 0;
	}else{
		a=1;
		if(s1[1]==s2[1]){
			b=1;
			if(s1[2]>='A'&&s1[2]<='c'&&s2[2]>='A'&&s2[2]<='C'){
				c=1;
				if(abs(s1[2]-s2[2])==1) d=1;
			}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				c=1;
				d=1;
			}
		}
	}cout<<a<<b<<c<<d;
	
} 
