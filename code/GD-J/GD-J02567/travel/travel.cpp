#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	bool f=0;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1,f=1;
	else cout<<0,f=0;
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&f==1)cout<<1,f=1;
	else cout<<0,f=0;
	if((a2[2]<='C'&&f==1&&b2[2]<='C')||(a2[2]>='D'&&f==1&&b2[2]>='D'))cout<<1,f=1;
	else cout<<0,f=0;
	if(abs(a2[2]-b2[2])==1&&f==1)cout<<1;
	else cout<<0;
	return 0;
} 
