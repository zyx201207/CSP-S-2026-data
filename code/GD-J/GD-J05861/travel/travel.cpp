#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
int f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    
    if(c1==c2){
    	cout<<"1";
    	f++;
	}else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f==1){
		cout<<"1";
		f++;
	}else{
		 cout<<"000";
		 return 0;
	}
	if((s1[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]<='F')&&f==2){
		cout<<"1";
		f++;
	}else{
		cout<<"00";
		return 0;
	}
	if((int)abs(s1[2]-s2[2])==1&&f==3){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
