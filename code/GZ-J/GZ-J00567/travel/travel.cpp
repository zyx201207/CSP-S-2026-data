//GZ-J00567;邱伟轩,贵阳市乌当第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=0,a2=0,a3=0,a4=0;
	if(c1[0]=c2[0]&&c1[1]==c2[1])a=1;
	if(a){
		if(s1[0]==s2[0]&&s1[1]==s2[1])a2=1;
	}
	if(a&&a2){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))a3=1;
	}
	if(a&&a2&&a3){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2])a4=1;
	}
	cout<<a<<a2<<a3<<a4;
	return 0;
}
