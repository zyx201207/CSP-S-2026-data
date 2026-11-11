#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2,s1,s2;
bool flag1=0,flag2=0;
cin>>c1>>s1>>c2>>s2;
int num1=0,num2=0;
for(int i=0;i<s1.length()-1;i++){
	num1*=10;
	num1+=s1[i]-'0';
}
for(int i=0;i<s2.length()-1;i++){
	num2*=10;
	num2+=s2[i]-'0';
}
if(c1!=c2){
	flag1=1;
}
if(num1!=num2){
	flag2=1;
}
if(!flag1)cout<<1;
else cout<<0;
if((!flag1)&&(!flag2))cout<<1;
else cout<<0;
int x=s1[s2.length()-1]-'A';
int y=s2[s2.length()-1]-'A';
if(((x>2&&y>2)||(x<3&&y<3))&&(!flag1)&&(!flag2)){
	cout<<1;
	if((max(x,y)-min(x,y)==1)&&(!flag1)&&(!flag2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
else{
	cout<<0<<0;
}
return 0;
} 
