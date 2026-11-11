#include<bits/stdc++.h>
using namespace std;

string c1,c2;
char s1[5],s2[5];
int ss1,ss2;
bool f1,f2,f3,f4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
	}
	for(int i=0;i<2;i++){
		ss1+=(s1[i]-'0')*pow(10,i);
		ss2+=(s2[i]-'0')*pow(10,i);
	}
	if(ss1==ss2&&f1==1){
		f2=1;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
		if(f2==1) f3=1;
	}
	if(f3==1&&abs(int(s1[2])-int(s2[2])<=1)){
		if(s1[2]!='C'&&s2[2]!='D'||s1[2]!='D'&&s2[2]!='C'){
			f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
