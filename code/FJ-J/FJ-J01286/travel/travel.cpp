#include <bits/stdc++.h>
using namespace std;
int c1,c2,l1,l2;
string s1,s2;
bool t=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	l1=(s1[0]-'0')*10+s1[1]-'0'; 
	l2=(s2[0]-'0')*10+s2[1]-'0';
	
	t=t&&(c1==c2);
	cout<<t;
	
	t=t&&(l1==l2);
	cout<<t;
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') t=t&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	else t=t&(s2[2]=='D'||s2[2]=='F');
	cout<<t;
	
	if(s1[2]=='A')t=t&(s2[2]!='C');
	else if(s1[2]=='C')t=t&(s2[2]!='A');
	cout<<t;
	return 0;
} 
