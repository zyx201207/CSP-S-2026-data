#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1[0]==a3[0]&&a1[1]==a3[1])
		cout<<1;
	else
	{
		cout<<"00"<<"00";
		return 0;
			
	}
	if(a2[0]==a4[0] && a2[1]==a4[1])
	{
		cout<<1;
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if((a2[2]<='C'&&a4[2]<='C')||(a2[2]>='D'&&a4[2]>='D'))
		cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	int m=a2[2]-'A',n=a4[2]-'A';
	if(abs(m-n)==1 || (a2[2]=='D'&&a4[2]=='F'))
		cout<<1;
	else 
		cout<<0;
}
