#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1];
	b=(s1[0]-'0')*10+s1[1];
	c=(c2[0]-'0')*10+c2[1];
	d=(s2[0]-'0')*10+s2[1];
	e=s1[2]-'A';
	f=s2[2]-'A';
	if(a!=c)cout<<"0000";
	else{
		cout<<1;
		if(b!=d)cout<<"000";
		else{
			cout<<1;
			if((e<4&&f>3)||(e>3&&f<4))cout<<"00";
			else{
				cout<<1;
				if(abs(e-f)==1)cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
} 
