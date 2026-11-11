#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char cc1,cc2;
int n1,n2,n3,n4,f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n1=(c1[0]-'0')*10+c1[1]-'0';
	n2=(s1[0]-'0')*10+s1[1]-'0';
	cc1=s1[2];
	n3=(c2[0]-'0')*10+c2[1]-'0';
	n4=(s2[0]-'0')*10+s2[1]-'0';
	cc2=s2[2];
	if(n1!=n3)f=0;
	cout<<f;
	if(n2!=n4)f=0;
	cout<<f;
	if(!(((cc1>='A')&&(cc1<='C')&&(cc2>='A')&&(cc2<='C'))||((cc1>='D')&&(cc2>='D'))))f=0;
	cout<<f;
	if(!(abs(int(cc2-cc1))==1))f=0;
	cout<<f;
	return 0;
} 

