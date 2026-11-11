#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,sum;

int main(){
cin>>c1>>s1>>c2>>s2;

if(c1==c2)sum=sum+'1';
else {
cout<<"0000";
	return 0;
}
if(s1[0]+s1[1]==s2[0]+s2[1])sum=sum+'1';
else {
cout<<"1000";
	return 0;
}
if(s2[2]>='D'&&s1[2]>='D'||s2[2]<'D'&&s1[2]<'D')sum=sum+'1';
else {
cout<<"1100";
	return 0;
}if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)sum=sum+'1';
else {
cout<<"1110";
	return 0;
}
cout<<sum;
return 0;
}
