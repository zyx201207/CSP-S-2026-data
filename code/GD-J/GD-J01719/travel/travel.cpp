#include<bits/stdc++.h>
using namespace std;
string R1,R2,X1,X2;
void is(string n,string m)
{
	int a=0,b=0;
	char a2,b2;
	for(int i=n.size()-1;i>=0;i--)
	{
		if(isdigit(n[i]))
		{
			a=a*10+(n[i]-'0');
			b=b*10+(m[i]-'0');
		}else
		{
			a2=n[i];b2=m[i];
		}
	}
	if(a==b)
	{
		cout<<1;
	}else{
		cout<<"000";return;
	}
	if((a2<='C' && b2<='C') || (a2>'C' && b2>'C'))
	{
		cout<<1;
	}else{
		cout<<"00";return;
	}
	if((a2=='A' && b2=='B') || (a2=='B' && b2=='C') || (a2=='D' && b2=='F'))
	{
		cout<<1;
	}else cout<<0;
	return;
}
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R1>>R2>>X1>>X2;
	if(R1==X1)
	{
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	is(R2,X2);
	return 0;
}
