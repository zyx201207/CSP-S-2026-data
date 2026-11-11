#include<bits/stdc++.h>
using namespace std;
char a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>a1>>a2>>a3>>a4>>a5;
	cin>>b1>>b2>>b3>>b4>>b5;
	if(a1==b1&&a2==b2)
	{
		cout<<1;
	}
	else
	{
	cout<<"0000";
	return 0;	
	}
	if(a3==b3&&a4==b4)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";return 0;
	}
	if(a5=='F'||a5=='D')
	{
		if(b5=='F'||b5=='D')
		{
			cout<<"11";return 0;
		}
		else
		{
			cout<<"00";return 0;
		}
	}
	else
	{
		if(b5=='F'||b5=='D')
		{
			cout<<"00";return 0;
		}
		else
		{
			cout<<1;
		}
	}
	if(abs(a5-b5)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
