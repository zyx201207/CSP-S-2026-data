#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a=0,b=0,c=0,d=0;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    s1=s1[0]*10+s1[1];
    s2=s2[0]*10+s2[1];
    a1=c1[0]*10+c1[1];
    a2=c2[0]*10+c2[1];
    if(s1==s2) {
    	a=1;
    	if(a1==a2){
    		b=1;
    		if((c1[2]=='F'&&c2[2]=='D')||(c1[2]=='D'&&c2[2]=='F')||(c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='A')||(c1[2]=='C'&&c2[2]=='A')||(c1[2]=='A'&&c2[2]=='C')||(c1[2]=='B'&&c2[2]=='C')||(c1[2]=='C'&&c2[2]=='B')){
    			c=1;
    			d=1;
    			if((c1[2]=='A'&&c2[2]=='C')||c1[2]=='C'&&c2[2]=='A') d=0;
			}
		} 
	}
	cout<<a<<b<<c<<d;
	return 0;
}
