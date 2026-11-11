#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string cx1,zw1,cx2,zw2;
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(zw1.substr(0,2)==zw2.substr(0,2))cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char op1=zw1[2];
	char op2=zw2[2];
	if(op1=='A')
	{
		if(op2=='B'||op2=='C')cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(op1=='B')
	{
		if(op2=='A'||op2=='C')cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(op1=='C')
	{
		if(op2=='B'||op2=='A')cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(op1=='D')
	{
		if(op2=='F')cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		if(op2=='D')cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(op1=='A'&&op2=='B')cout<<1;
	else if(op1=='B'&&op2=='C')cout<<1;
	else if(op1=='D'&&op2=='F')cout<<1;
	else if(op2=='A'&&op1=='B')cout<<1;
	else if(op2=='B'&&op1=='C')cout<<1;
	else if(op2=='D'&&op1=='F')cout<<1;
	else cout<<0;
	return 0;
}

/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A

1111
1110
1100
1000
0000
*/
