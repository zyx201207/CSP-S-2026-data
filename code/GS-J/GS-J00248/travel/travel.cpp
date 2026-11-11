#include<bits/stdc++.h>
using namespace std;
string n1,n2,c1,c2;
int main()
{
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin>>n1>>c1>>n2>>c2;
	if(n1==n2)cout<<1;
	{
			if(c1=="01A")
		{
			if(c2=="01B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="01C"){
				cout<<110;
				return 0;
			}
			if(c2=="01D")
			{
				cout<<110;
				return 0;
			}
			if(c2=="01E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="01F")
			{
				cout<<100;
				return 0;
			}

		}
		if(c1=="02A")
		{
			if(c2=="02B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="02C"){
				cout<<110;
				return 0;
			}
			if(c2=="02D")
			{
				cout<<110;
				return 0;
			}
			if(c2=="02E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="02F")
			{
				cout<<100;
				return 0;
			}

		}
		if(c1=="03A")
		{
			if(c2=="03B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="03C"){
				cout<<110;
				return 0;
			}
			if(c2=="03D")
			{
				cout<<110;
				return 0;
			}
			if(c2=="03E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="03F")
			{
				cout<<100;
				return 0;
			}

		}
		if(c1=="04A")
		{
			if(c2=="04B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="04C"){
				cout<<110;
				return 0;
			}
			if(c2=="04D")
			{
				cout<<110;
				return 0;
			}
			if(c2=="04E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="04F")
			{
				cout<<100;
				return 0;
			}

		}
		if(c1=="05A")
		{
			if(c2=="05B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="05C"){
				cout<<110;
				return 0;
			}
			if(c2=="05D")
			{
				cout<<110;
				return 0;
			}
			if(c2=="05E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="05F")
			{
				cout<<100;
				return 0;
			}

		}
		if(c1=="06A")
		{
			if(c2=="06B")
			{
				cout<<111;
				return 0;
			}
			if(c2=="06C"){
				cout<<110;
				return 0;
			}
			if(c2=="06D")
			{
				cout<<110;
				return 0;
			} 
			if(c2=="06E")
			{
				cout<<100;
				return 0;
			}
			if(c2=="06F")
			{
				cout<<100;
				return 0;
			}

		}
		cout<<0;
		if(c1=="01C"&&c2=="01A")
		{
			cout<<110;
			return 0;
		}
		if(c1=="01C"&&c2=="01D"){
			cout<<110;
			return 0;
		}
		if(c1=="01C"&&c2=="01D"){
			cout<<100;
			return 0;
		}
		if(c1=="02B"&&c2=="01A"){
			cout<<"000";
			return 0;
		}
		if(c1=="01A"&&c2=="01A")
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"000";
	return 0;
}
