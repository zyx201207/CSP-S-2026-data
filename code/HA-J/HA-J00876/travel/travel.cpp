#include<bits/stdc++.h>
using namespace std;
int f1,f2,f3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<1;
		f1=1;
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	string sr="",sx="";
	for(int i=0;i<s1.size()-1;i++)
		sr+=s1[i];
	for(int i=0;i<s2.size()-1;i++)
		sx+=s2[i];
	if(sr==sx&&f1==1)
	{
		cout<<1;
		f2=1;
	} 
	else 
	{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')&&f1==1&&f2==1)
	{
		cout<<1;
		f3=1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)&&f1==1&&f2==1&&f3==1)
	cout<<1;
	else cout<<0;
	return 0;
}
