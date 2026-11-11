#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f=0,f1=0,f2=0;
	if(c1==c2){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && f2==1){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	if(s1[2]<='C' && s2[2]<='C' && f1==1){
		cout<<1;
		f=1;
	}else if(s1[2]>='D' && s2[2]>='D' && f1==1){
		cout<<1;
		f=1;
	}else{
		cout<<0;
		f=0;
	}
	if(f==0){
		cout<<0;
	}else if(abs(s1[2]-s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
}
	
	