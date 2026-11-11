#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	if(c1==c2){
		cout<<"1";
		d=1;
	}else{
		cout<<"0";
		d=0;
	}
	if(s1[1]==s2[1]&&d==1){
		cout<<"1";
		b=1;
	}else{
		cout<<"0";
		b=0;
	}
	if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')){
		c=1;
	}else{
		c=0;
	}
	if(b==1&&c==1&&d==1){
		cout<<"1";
		a=1;
	}else{
		cout<<"0";
		a=0;
	}
	if((s1[2]-1==s2[2]&&a==1&&b==1&&d==1)||(s1[2]+1==s2[2]&&a==1&&b==1&&d==1)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
 
