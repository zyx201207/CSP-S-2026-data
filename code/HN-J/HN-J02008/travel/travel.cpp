#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
string s1_1,s1_2,s2_1,s2_2;
bool check1(){
	if((s1_2=="A")||(s1_2=="B")||(s1_2=="C")){
		if((s2_2=="A")||(s2_2=="B")||(s2_2=="C")){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if((s2_2=="D")||(s2_2=="F")){
			return 1;
		}
		else{
			return 0;
		}
	}
}
bool check2(){
	if(s1_2=="A"){
		if(s2_2=="B"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(s1_2=="B"){
		if((s2_2=="A")||(s2_2=="C")){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(s1_2=="C"){
		if((s2_2=="B")){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(s1_2=="D"){
		if(s2_2=="F"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(s1_2=="F"){
		if(s2_2=="D"){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	s1_1+=s1[0];
	s1_1+=s1[1];
	s2_1+=s2[0];
	s2_1+=s2[1];
	
	s1_2+=s1[2];
	s2_2+=s2[2];
	
	bool flag1=0;
	if(c1==c2){
		ans+="1";
		flag1=1;
	}
	else{
		ans+="0";
	}
	
	bool flag2=0;
	if((flag1==1)&&(s1_1==s2_1)){
		flag2=1;
		ans+="1";
	}
	else{
		ans+="0";
	}
	
	bool flag3=0;
	if((flag2==1)&&(check1()==1)){
		flag3=1;
		ans+="1";
	}
	else{
		ans+="0";
	}
	
	if((flag3==1)&&(check2()==1)){
		ans+="1";
	}
	else{
		ans+="0"; 
	}
	
	cout<<ans;
	
	return 0;
}
