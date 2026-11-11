#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];
bool sign;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1; i<=3; i++) cin>>s1[i];
	cin>>c2;
	for(int i=1; i<=3; i++) cin>>s2[i];
	if(c1==c2) 
	{
		cout<<"1";	
		sign=true;	
	}
	else 
	{
		cout<<"0";
		sign=false;
	}
	if(sign && s1[1]==s2[1] && s1[2]==s2[2]) 
	{
		cout<<"1";
		sign=true;
	}
	else
	{
		cout<<"0";
		sign=false;
	} 
	if(sign && s1[3]<='C'-0 && s2[3]<='C'-0 ) 
	{
		cout<<"1";
		if(s1[3]-s2[3]==1 || s2[3]-s1[3]==1) cout<<"1";
		else cout<<"0";
	}
	else if(sign && s1[3]>='D'-0 && s2[3]>='D'-0) 
	{
		cout<<"1";
		if(s1[3]-s2[3]==1 || s2[3]-s1[3]==1) cout<<"1";
		else cout<<"0";
	}
	else
	{
		cout<<"0";
		sign=false;
		cout<<"0";
	}
	
	return 0;
}
