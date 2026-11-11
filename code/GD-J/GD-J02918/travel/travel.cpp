#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,pd;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	ll t1=(s1[0]-'0')*10+(s1[1]-'0');
	ll t2=(s2[0]-'0')*10+(s2[1]-'0');
	char c1=s1[2],c2=s2[2];
	if(x==y)	cout<<1;
	else	cout<<0;
	if(x==y&&t1==t2)	cout<<1;
	else	cout<<0;
	if(x==y&&t1==t2&&(c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))	cout<<1,pd=1;
	else	cout<<0;
	if(pd==1&&abs(c1-c2)==1)	cout<<1;
	else	cout<<0;
	return 0; 
}
