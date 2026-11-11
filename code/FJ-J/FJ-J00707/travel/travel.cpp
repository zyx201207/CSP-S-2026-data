#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=false;
	bool flag1=false;
	bool flag2=false;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		flag2=true;
		cout<<1;
	}
	else cout<<0;
	if(s1[0]==s2[0] && s1[1]==s2[1] && flag2==true ){
		flag1=true;
		cout<<1;
	}
	else cout<<0;
	if(s1[2]<='C' && s2[2]<='C' && flag1==true && flag2==true || s1[2]>='D' && s2[2]>='D'&& flag1==true && flag2==true ){
		cout<<1;
		flag=true;
	} 
	else cout<<0;
	if(s1[2]-s2[2]==1 && flag==true && flag1==true && flag2==true || s2[2]-s1[2]==1 && flag==true && flag1==true && flag2==true ){
		cout<<1;
	}else cout<<0;
	return 0;
} 
