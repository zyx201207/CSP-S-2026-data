#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char ch,sh;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>ch>>c>>d>>sh;
	if(a==c&&f)cout<<1;
	else {
		cout<<0;
		f=0;
	}if(b==d&&f)cout<<1;
	else {
		cout<<0;
		f=0;
	}if(ch>='A'&&ch<='C'&&sh>='A'&&sh<='C'&&f)cout<<1;
	else if((ch=='D'||ch=='F')&&(sh=='D'&&sh=='F')&&f)cout<<1;
	else {
		cout<<0;
		f=0;
	}if(f&&(abs(ch-sh)==1||(ch=='D'&&sh=='F')||(ch=='F'&&sh=='D')))cout<<1;
	else cout<<0;
	return 0;
} 
