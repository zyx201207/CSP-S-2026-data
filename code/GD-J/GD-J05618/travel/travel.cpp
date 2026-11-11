#include<bits/stdc++.h>
using namespace std;	
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		if(s1.substr(0,1)==s2.substr(0,1)){
			b=1;
			if(s1[2]>='D'&&s2[2]>='D'||s1[2]<'D'&&s2[2]<'D'){
				c=1;
				if(abs(s1[2]-s2[2])==1)d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	
	return 0;
}
 
