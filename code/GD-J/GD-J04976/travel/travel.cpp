#include<iostream>
#include<cmath>
using namespace std;
int c1,c2;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	bool f1=false,f2=false,f3=false,f4=false;
	if(c1==c2){
		f1=true;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && f1){
		f2=true;
	}
	
	if(f1 && f2){
		if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') f3=true;
		else if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')) f3=true;
	}
	
	if(f1 && f2 && f3){
		if(abs(s1[2]-s2[2])==1) f4=true;
	}
	
	if(f1) cout<<1;
	else cout<<0;
	
	if(f2) cout<<1;
	else cout<<0;
	
	if(f3) cout<<1;
	else cout<<0;
	
	if(f4) cout<<1;
	else cout<<0;
	return 0;
}
