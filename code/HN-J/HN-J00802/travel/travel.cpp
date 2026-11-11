#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[3],s2[3];
	bool flag=1,sf=0;
	cin>>c1;
	for(int i=0;i<=2;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<=2;i++)
	{
		cin>>s2[i];
	}
	int x1=int(s1[0]);
	int x2=int(s2[0]); 
	int y1=int(s1[1]);
	int y2=int(s2[1]);
	int z1=int(s1[2]); 
	int z2=int(s2[2]);
	int a1=int(c1[0]);
	int a2=int(c2[0]);
	int b1=int(c1[1]);
	int b2=int(c2[1]);
	if(a1==a2 and b1==b2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(x1==x2 and y1==y2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(z1==65||z1==66||z1==67)
	{
		sf=1;
		if(z2==68||z2==70)
		{
			cout<<"00";
 			return 0;
		}
		else if(z2==65||z2==66||z2==67 and z2!=z1)
		{
			cout<<"1";
		}
	} 
	if(z2==65||z2==66||z2==67)
	{
		if(z1==68||z1==70)
		{
			if(sf==0)
			{
				cout<<"00";
				return 0;
			}
			
		}
		else if(z1==65||z1==66||z1==67 and z1!=z1)
		{
			if(sf==0)
			{
				cout<<"1";
			}
		}
	} 
	if(z1-z2==1||z2-z1==1 and flag==1)
	{
		cout<<"1";
		return 0;
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
