#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n[13],c,s,c2,s2;
	cin>>n;
	if(n[2]=n[9])
	{
		cout<<"11";
	}
	else
	{
		cout<<"00";
	}
	if(int(n[6])+1==int(n[13])||int(n[6])==int(n[13])+1)
	{
		cout<<"11";
	}
	else
	{
		cout<<"00"
	}
	
	return 0;	
} 
