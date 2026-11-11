//GZ-J00602 遵义市第四初级中学  彭紫宸 
#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
int ax,bx;
string az,bz;
cin>>ax>>az>>bx>>bz;
string s;
string a,b;
a=az;
b=bz;
if(ax==bx){
s=s+'1';

az.erase(2,1);
bz.erase(2,1);
if(az==bz){
	s=s+'1';
	az=a.erase(0,2);
    bz=b.erase(0,2);
	if(az>="A" && az<="C" and bz>="A"&& bz<="C"){
	s=s+'1';
	if(az=="A" && bz=="C" or az=="C" && bz=="A"){
		s=s+'0';
	}
	else{
		s=s+'1';
	}
}
if(az>="A" && az<="C" and bz>="D"&& bz<="F"){
	s=s+'0';
	s=s+'0';
}
if(az>="D" && az<="F" and bz>="D"&& bz<="F"){
	s=s+'1';
	s=s+'1';
}	
}
else{
	cout<<"1000";
	return 0;
}
}
else{
	cout<<"0000";
	return 0;
}
cout<<s;
}
