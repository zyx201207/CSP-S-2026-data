#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s[5];
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","s",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1>c2) swap(c1,c2);
	if(s1>s2) swap(s1,s2); 
	s[0]="0";s[1]="0";s[2]="0";s[3]="0";
	if(c1==c2) 
	{s[0]="1";s[1]="0";s[2]="0";s[3]="0";
	if(s1.substr(0,2)==s2.substr(0,2))
	{
		s[0]="1";s[1]="1";s[2]="0";s[3]="0";
		if(((s1.substr(2,1)>="A"&&s1.substr(2,1)<"D")&&(s2.substr(2,1)>="A"&&s2.substr(2,1)<"D"))||((s1.substr(2,1)=="D"||s1.substr(0,2)=="F")&&(s2.substr(2,1)=="D"&&s2.substr(2,1)=="F")))
			{
			 s[0]="1";s[1]="1";s[2]="1";s[3]="0";	
			 if((s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")||(s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")||(s1.substr(2,1)=="D"&&s2.substr(2,1)=="F"))
			 {s[0]="1";s[1]="1";s[2]="1";s[3]="1";}
			}
	}
	}
	cout<<s[0]<<s[1]<<s[2]<<s[3];
	return 0;
} 
