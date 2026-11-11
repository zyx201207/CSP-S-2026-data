//GZ-J00536，任轩辰，贵阳市南明区李端棻中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else{
		cout<<"0";
		a=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a)
		cout<<"1";
	else{
		cout<<"0";
		a=0;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&a)
		cout<<"1";
	else if(s1[2]>'C'&&s2[2]>'C'&&a)
		cout<<"1";
	else{
		cout<<"0";
		a=0;
	}
	if(abs(int(s1[2])-int(s2[2]))==1&&a){
		cout<<"1";
	}
	else
		cout<<"0";
	return 0;
} 
