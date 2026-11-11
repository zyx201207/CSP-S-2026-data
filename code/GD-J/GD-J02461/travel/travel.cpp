#include<bits/stdc++.h>
using namespace std;
char A(char a[3],char b[3]){
	if(a[2]=='F'){
		if(b[2]!='D')return 0;
	}
	if(a[2]=='A'){
		if(b[2]!='C'||b[2]!='B'||b[2]=='F'||b[2]=='D')return 0;
	}
	if(a[2]=='B'){
		if(b[2]!='C'||b[2]!='A'||b[2]=='F'||b[2]=='D')return 0;
	}
	if(a[2]=='C'){
		if(b[2]!='B'||b[2]!='A'||b[2]=='F'||b[2]=='D')return 0;
	}
}
int main(){
    int c1,c2; 
	char s1[3],s2[3];
    cin>>c1>>s1>>c2>>s2;
    if(c1<=0||c1>17||c2<=0||c2>17)return 0;
    
	if(s1[2]<='F'||s1[2]>='A'||s1[2]!='E'||s2[2]<='F'||s2[2]>='A'||s2[2]!='E')return 0;
    if(c1==c2)cout<<1;
    int s=s1[0]*10+s1[1];
    int ss=s2[0]*10+s2[1];
    if(s<0||s>18||ss<0||ss>18)return 0;
    if(s==ss)cout<<1;
    if((c1==c2)&&(s==ss)&&A(s1,s2))cout<<1;
    if(s1[2]=='F'&&s2[2]=='D')cout<<1;
    	
	
    
    
		
		
        
        

}

