//ÀîéÈº­ GZ-J00046
#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int r1,r2,r3,r4;
int my_abs(int x){
	if(x<0)return -x;
	return x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		r1=1;
	}
	if(r1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		r2=1;
	}
	if(r2&&((s1[2]>='D'&&s2[2]>='D')||
	(s1[2]<='C'&&s2[2]<='C')
	)){
		r3=1;
	}
	if(r3&&my_abs(s1[2]-s2[2])<=1){
		r4=1;
	}
	cout<<r1<<r2<<r3<<r4;
	return 0;
}
