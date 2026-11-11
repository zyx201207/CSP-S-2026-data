#include<bits/stdc++.h>
using namespace std;

char seat1[5],seat2[5];
char num1[5],num2[5];
int main()
{
	freopen("tarvel.in","r",stdin);
	//freopen("tarvel1.in","r",stdin);
	freopen("tarvel.out","w",stdout);
	for(int i=0;i<2;i++) 
	cin>>num1[i];
	for(int i=0;i<3;i++)
	cin>>seat1[i];
	for(int i=0;i<2;i++)
	cin>>num2[i];
	for(int i=0;i<3;i++)
	cin>>seat2[i];
	if(num1[0]!=num2[0]||num1[1]!=num2[1])
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(seat1[0]!=seat2[0]||seat1[1]!=seat2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(seat1[2]<='C'&&seat2[2]>='D')
	{
		cout<<"00";
		return 0;
	}
	if(seat2[2]<='C'&&seat1[2]>='D')
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(seat1[2]<='C'&&seat2[2]<='C'&&seat1[2]-seat2[2]!='A'-'B'&&seat2[2]-seat1[2]!='A'-'B')
	{
		cout<<0;
		return 0;
	}
	cout<<1;
}
