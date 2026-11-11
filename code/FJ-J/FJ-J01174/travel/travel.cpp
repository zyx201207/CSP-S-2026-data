#include<bits/stdc++.h>
using namespace std;
int a,b,a1,b1;
string n,n1;
int a2,b2,c2,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>n>>a1>>n1;
	b=(n[0]-'0')*10+(n[1]-'0');
	b1=(n1[0]-'0')*10+(n1[1]-'0');
	if(a==a1) a2=1;
	if(a2 && b==b1) b2=1;
	if(b2 && ((n[2]<='C' && n1[2]<='C') || (n[2]>'C' && n1[2]>'C'))) c2=1;
	if(c2 && abs(n1[2]-n[2])==1) d2=1;
	cout<<a2<<b2<<c2<<d2;
	
} 
