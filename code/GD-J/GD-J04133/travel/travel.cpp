#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool a=0,b=0,c=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)a=1;
	
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	
	if(a&&p1==p2)b=1;
	
	bool l=0,r=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')l=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')r=1;
	
	if(b&&l==r)c=1;
	
	if(c&&abs(s1[2]-s2[2])==1)d=1;
	
	cout<<a<<b<<c<<d;
	
	return 0;
} 
