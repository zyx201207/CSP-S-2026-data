#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;;
	if(a==c)
	cout<<1;
	else 
	{
		cout<<0<<0<<0<<0;
		exit(0);
	}
	for(int i=0;i<2;i++)
	{
		if(b[i]!=d[i])
		{
			cout<<0<<0<<0;
			exit(0);
		}
		if(i==1)
		cout<<1;
	}
	if(b[2]=='A')b[2]='1';
	if(b[2]=='B')b[2]='2';
	if(b[2]=='C')b[2]='3';
	if(b[2]=='D')b[2]='4';
	if(b[2]=='F')b[2]='5';
	if(d[2]=='A')d[2]='1';
	if(d[2]=='B')d[2]='2';
	if(d[2]=='C')d[2]='3';
	if(d[2]=='D')d[2]='4';
	if(d[2]=='F')d[2]='5';
	if((b[2]>='4'&&d[2]>='4')||(b[2]<='3'&&d[2]<='3'))
	cout<<1;
	else 
	{
		cout<<0<<0;
		exit(0);
	}
	if(((b[2]-48)-(d[2]-48)==1)||((d[2]-48)-(b[2]-48)==1))
	cout<<1;
	else cout<<0;
	return 0;
}