#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int arr[100006]={};
	string are[100006]={};
	for(int i=0;i<2;i++)
	{
		cin>>arr[i];
		cin>>are[i];
	}
	if(arr[0]!=arr[1])
	{
		cout<<"0000";
		return 0;
	}
	if(arr[0]==arr[1])
	{
		cout<<1;
	}
	if(are[0][0]==are[1][0] && are[0][1]==are[1][1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((are[0][2]-65<3 && are[1][2]-65<3) || (are[0][2]-65>=3 && are[1][2]-65>=3))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(are[0][2]-65==5)
	{
		if(are[0][2]-67==are[1][2]-65)
		{
			cout<<"1";
			return 0;
		}
	}
	if(are[1][2]-65==5)
	{
		if(are[1][2]-67==are[0][2]-65)
		{
			cout<<"1";
			return 0;
		}
	}
	if(are[0][2]-66==are[1][2]-65 || are[0][2]-64==are[1][2]-65)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
