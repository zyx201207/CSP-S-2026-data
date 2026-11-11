#include<iostream>
#include<string>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int q1=0,q2=0,q3=0,q4=0;
if(c1[0]==c2[0]&&c1[1]==c2[1])q1=1;
if(q1==1&&s1[0]==s2[0]&&s1[1]==s2[1])q2=1;
if(q2==1){
	if(s1[2]>='D'&&s2[2]>='D'){
		q3=1;
		q4=1;
	}
	if(s1[2]<='C'&&s2[2]<='C')q3=1;
}
if(q3==1&&(s1[2]=='B'||s2[2]=='B'))q4=1;
cout<<q1<<q2<<q3<<q4;
return 0;
}
