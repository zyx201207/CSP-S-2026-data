#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool flag;
	if(c1==c2){
		cout<<1;
		flag=true;
	}
	else {
		cout<<0;
		flag=false;
	}
	bool flag1=false;
	if(flag==true){
		for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			flag1=true;
		}
		else{
			flag1=false;
			break;
		}
	}
	}
	
	if(flag1==true)cout<<1;
	else cout<<0;
	bool flag2=false;
	if(flag==false||flag1==false){
		cout<<0;
	}
	else{
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]>='D'&&s2[2]<='F')){
			cout<<1;
			flag2=true;
		}
		else cout<<0;
	}
	if(flag2==false){
		cout<<0;
	}
	else{
		if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]){
			cout<<1;
		}
		else cout<<0;
		
	}
	
		return 0;
} 
