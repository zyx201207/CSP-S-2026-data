#include <bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,s11,s22;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	s11=int(ss1-'A');
	s22=int(ss2-'A');
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}
	
	if((s11<=2 && s22<=2)||(s11>=3 && s22>=3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(abs(s11-s22)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
