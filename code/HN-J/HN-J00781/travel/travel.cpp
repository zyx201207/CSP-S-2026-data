#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int a1,a2;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	a1=s1[0]-'0';
	a2=s2[0]-'0';
	a1=a1*10+s1[1]-'0';
	a2=a2*10+s2[1]-'0';
	ch1=s1[2];
	ch2=s2[2];
	if(a1==a2&&c1==c2)cout<<1;
	else cout<<0;
	if(a1==a2&&c1==c2){
		if(ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C')cout<<1;
		else if(ch1>='D'&&ch1<='E'&&ch2>='D'&&ch2<='E')cout<<1;
		else cout<<0;
		if(ch1=='C'&&ch2=='D')cout<<0;
		else if(ch1=='D'&&ch2=='C')cout<<0;
		else if(int(ch1)+1==int(ch2)||int(ch1)-1==int(ch2))cout<<1;
		else cout<<0;
	}
	else{
		cout<<0<<0;
	}
	return 0;
} 
