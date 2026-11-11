#include<bits/stdc++.h>
using namespace std;
int nn,nm,mn,mm;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>nn>>nm>>a>>mn>>mm>>b;
	if(nn!=mn)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(nm!=mm)
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if(a>='D'&&b>='D'||a<='C'&&b<='C')
	{
		if(a=='C')
		 if(b=='A')
		 {
		 	cout<<"1110"<<endl;
		 	return 0;
		 }
		if(a=='A')
		 if(b=='C')
		 {
		 	cout<<"1110"<<endl;
		 	return 0;
		 }
		cout<<"1111"<<endl;
		return 0;
	}
	else 
	{
		cout<<"1100"<<endl;
		return 0;
	}
}
