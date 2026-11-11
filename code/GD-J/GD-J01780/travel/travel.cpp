#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool a1,a2,a3,a4;
	cin>>c1>>s1>>c2>>s2;
	a1=(c1==c2);
	a2=(s1.substr(0,s1.size()-1)==s2.substr(0,s2.size()-1))&&a1;
	a3=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&a2;
	a4=(abs(s1[2]-s2[2])==1)&&a3;
	cout<<a1<<a2<<a3<<a4;
} 
