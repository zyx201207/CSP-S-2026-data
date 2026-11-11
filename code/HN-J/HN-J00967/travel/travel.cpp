#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2,da="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		da[0]='1';
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){

			da[1]='1';
			char z1=s1[2];
			char z2=s2[2];
			
			if((z1>='A'&&z1<='C') && (z2>='A'&&z2<='C')){
				da[2]='1';
				int cha=(z1-'A')-(z2-'A');
				if(cha<0) cha=-cha;
				if(cha<=1) da[3]='1';
			}else if((z1>='D'&&z1<='F') && (z2>='D'&&z2<='F')){
				da[2]='1';
				da[3]='1';				
			}	
		}			
	}
	
	cout<<da;
	return 0;
}
