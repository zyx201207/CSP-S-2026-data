#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//Trick||Treat!
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char x1=s1[2],x2=s2[2];
	if((s1[2]<='C'&&s2[1]<='C')||(s1[2]>'C'&&s2[2]>'C'))
	{
		if(x1=='C'&&x2=='D')
		{
			cout<<"00";
			return 0;
		}
		if(x1=='D'&&x2=='C')
		{
			cout<<"00";
			return 0;
		}
		cout<<1;
	}
	
	//02 01C 02 01D
	if(abs(x1-x2)==1)
	{
		if(x1=='C'&&x2=='D')
		{
			cout<<0;
			return 0;
		}
		if(x1=='D'&&x2=='C')
		{
			cout<<0;
			return 0;
		}
		cout<<1;
	}
	else
		cout<<0;
	return 0;
}

