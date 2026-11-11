#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;
    if(c1==c2){
    	a=1;
    	if(s1[1]==s2[1]&&s1[0]==s2[0]){
	        b=1;
	        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		        c=1;
	        }
	        else if((s1[2]=='F'||s1[2]=='E')&&(s2[2]=='F'||s2[2]=='E')){
			    c=1;
	       }
	       if(c==1){
	       	    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
	       	        d=1;
		       }
		        else if((s1[2]=='F'&&s2[2]=='E')||(s1[2]=='E'||s2[2]=='F')){
		       	d=1;
			   }
           }
        }
	

    }
    cout<<a<<b<<c<<d;
    return 0;
    
    
    
    
    
    
    
    
    
    
}