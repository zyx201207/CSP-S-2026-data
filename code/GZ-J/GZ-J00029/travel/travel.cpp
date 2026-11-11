//GZ-J00029 КЋСиаї 
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char  a1,a2,a3,a4,b1,b2,b3,b4,a5,b5;
cin>>a1>>a2>>a3>>a4>>a5;
cin>>b1>>b2>>b3>>b4>>b5;
int num=a5-'A',sum=b5-'A'; 
if(a1==b1&&a2==b2){
	cout<<1;
}
else{
	cout<<0<<0<<0<<0;
	return 0;
}
if(a3==b3&&a4==b4){
	cout<<1;
}
else{
	cout<<0<<0<<0;
	return 0;
}
if(num<=3&&num>=0&&sum<=3&&sum>=0){
	cout<<1;
}
else if(num<=5&&num>=4&&sum<=5&&sum>=4){
	cout<<1;
}
else{
	cout<<0<<0;
	return 0;
}
if(a5+1==b5||b5+1==a5){
	if(a5!='C'&&b5!='D'){
		cout<<1;
	}
}
else{
	cout<<0;
}
return 0;
}
