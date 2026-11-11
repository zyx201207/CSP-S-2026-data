#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string z1="";
		z1=z1+s1[0]+s1[1];
		string z2="";
		z2=z2+s2[0]+s2[1];
		if(z1==z2){
			if(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'){
				if(abs(s1[2]-s2[2])==1) cout<<"1111";
				else cout<<"1110";
			}else if(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='E'&&s2[2]<='E') cout<<"1111";
			else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
} 
