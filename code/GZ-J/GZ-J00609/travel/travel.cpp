//GZ-J00609 息烽县第二中学 袁语晨 
#include<iostream>
using namespace std;
int main(){
	char c1,s1,c2,s2; 
	int a1,a2,a3,a4;
	if(c1==c2){
		a1=1;
	}
	else{
		a1=0;
	}
	if((s1-s2)<=5 || (s1-s2)>=-5){
		a2=1;
	}
	else{
		a2=0;
	}
	if(((s1-s2)<=5 || (s1-s2)>=-5) && ((s1+s2)<=195 || (s1+s2)<=199)){
		a3=1;
	}
	else{
		a3=0;
	}
	if((((s1+s2)<=195) && ((s1-s2)==1 || (s1-s2)==-1)) || (((s1+s2)<=199) && ((s1-s2)==1 || (s1-s2)==-1))){
		a4=1;
	}
	else{
		a4=0;
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
