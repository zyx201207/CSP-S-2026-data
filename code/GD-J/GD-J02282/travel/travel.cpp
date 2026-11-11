#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
string x;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) x+="1";
	else{
		cout<<"0000";
		return 0;
	}
	a=s1;
	b=s2;
	s1.erase(2,1);
	s2.erase(2,1);
	if(s1==s2) x+="1";
	else{
		cout<<"1000";
		return 0;
	}
	a.erase(0,2);
	b.erase(0,2);
	if(((a=="A"||a=="B"||a=="C")&&(b=="A"||b=="B"||b=="C"))||((a=="D"||a=="E")&&(b=="D"||b=="E"))) x+="1";
	else x+="0";
	if((a=="A"&&b=="B")||(a=="B"&&b=="C")||(b=="A"&&a=="B")||(b=="B"&&a=="C")||(a=="D"&&b=="E")||(b=="D"&&a=="E")) x+="1";
	else x+="0";
	cout<<x;
	return 0;
}

