#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char z1,z2;
int f(char a,char b){
	if((a<=67&&b<=67)||(a>67&&b>67)){
		return 1;
	}else{
		return 0;
	}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>z1>>c2>>s2>>z2;
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
	if((c1==c2)&&(s1==s2)){
		cout<<1;
	}else{
		cout<<0;	
	}
	if((c1==c2)&&(s1==s2)&&(f(z1,z2)==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((char(z1-1)==z2)||(char(z1+1)==z2))&&(f(z1,z2)==1)&&(c1==c2)&&(s1==s2)){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}

