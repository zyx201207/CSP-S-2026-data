#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,c4;
	long long c1,c3,a,b,c,d;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		a=1;
	} 
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c2[1]!=c4[1])
	{
		cout<<1000;
		return 0;
	}
	else b=1;
	if((c2[2]=='F'&&c4[2]=='E')||(c2[2]=='E'&&c4[2]=='F'))
	{
		c=1;
	}
	else if((c2[2]!='F'&&c4[2]!='E')&&(c2[2]!='E'&&c4[2]!='F'))
	{
		c=1;
	}
	else 
	{
		cout<<1<<1<<0<<0;
		return 0;
	}
	if(abs(c2[2]-c4[2])==1)
	{
		cout<<1111;
	}
	else cout<<1110;
	return 0;
}
