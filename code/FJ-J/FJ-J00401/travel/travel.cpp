#include <bits/stdc++.h>
using namespace std;
string a,aa,b,bb;

bool v1,v2,v3,v4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a[0]==b[0] && a[1]==b[1])
	{
		cout<<"1";
		v1=true;
	}
	else
	{
		cout<<"0";
		v1=false;
	}
	
	
	if(v1==true && aa[0]==bb[0] && aa[1]==bb[1])
	{
		v2=true;
		cout<<"1";
	}
	else
	{
		cout<<"0";
		v2=false;
	}
	
	if(v2==true)
	{
		bool flag=false;
		if(aa[2]=='A' || aa[2]=='B' || aa[2]=='C')
		{
			flag=true;
		}
		
		if(((bb[2]=='A' || bb[2]=='B' || bb[2]=='C') && flag==true) || ((bb[2]=='D' || bb[2]=='F') && flag==false))
		{
			cout<<"1";
			v3=true;
		}
		else
		{
			cout<<"0";
			v3=false;
		}
	}
	else
	{
		cout<<"0";
		v3=false;
	}
	
	//cout<<"\n"<<abs((int)aa[2]-(int)bb[2])<<"\n";
	if(v3==true && abs((int)aa[2]-(int)bb[2])==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
