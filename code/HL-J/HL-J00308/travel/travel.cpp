#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	if(c1==s1){
		flag1=1;
	}
	string k1=c2.substr(0,2),k2=s2.substr(0,2);
	char m1=c2[2],m2=s2[2];
	if(flag1==1&&k1==k2){
		flag2=1;
	}
	if(flag2==1&&(m1<='C'&&m2<='C')||(m1>='D'&&m2>='D')){
		flag3=1;
	}
	if(flag3==1&&abs(m1-m2)==1){
		flag4=1;
	}cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
