#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;	
	int ok1,ok2,ok3,ok4;
	if(c1==c2)ok1=1;
	else ok1=0;
	string cc,ss;
	cc=s1[0]+s1[1];
	ss=s2[0]+s2[1];
	if(ok1&&cc==ss)ok2=1;
	else ok2=0;
	if(ok1&&ok2&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))ok3=1;
	else ok3=0;
	int x,y;
	x=s1[2]-'A';
	y=s2[2]-'A';
	if(ok1&&ok2&&ok3&&abs(x-y)==1)ok4=1;
	else ok4=0;
	cout<<ok1<<ok2<<ok3<<ok4; 
	return 0;
} 
