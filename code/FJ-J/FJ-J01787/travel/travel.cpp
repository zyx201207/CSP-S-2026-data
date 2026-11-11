#include<bits/stdc++.h>
using namespace std;
int main(){
	bool flag=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		exit(0);
	}
	
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		flag=1;
		if(s1[1]==s2[1]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	
	if(flag==1&&(((s1[0]+s1[1]==s2[0]+s2[1])&&((abs(int(s1[2])-int(s2[2]))==1)||(int(s1[2])+int(s2[2]))==138)))||((s1[2]==s2[2])&&(abs(int(s1[1]+s1[0])-int(s2[1]+s2[0]))==1))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
