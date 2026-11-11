#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x="",s11="",s12="",s21="",s22="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s11=s1[0]+s1[1];
	s12=s1[2];
	s21=s2[0]+s2[1];
	s22=s2[2];
	if(c1==c2){
		x+="1";
		if(s11==s21){
			x+="1";
			if((s12=="D"&&s22=="F")||(s12=="F"&&s22=="d")) x+="11";
			else if((s12=="D"&&s22!="F")||(s12=="F"&&s22!="d")) x+="00";
			else if((s22=="D"&&s12!="F")||(s22=="F"&&s12!="d")) x+="00";
			else{
				x+="1";
				if(s12!="B"&&s22!="B") x+="0";
				else x+="1";
			}
		}
		else x+="000";
	}
	else x+="0000";	
	cout<<x;
	
	return 0;
} 
