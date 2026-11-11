#include<bits/stdc++.h>
using namespace std;
char a[13];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.getline(a,13);
	if(a[1]==a[8]&&a[0]==a[7])
	cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(a[3]==a[10]&&a[4]==a[11])
	cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	
	if(a[5]<='C'&&a[12]<='C')
	cout<<1;
	else if(a[5]>='D'&&a[12]>='D')
	cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(a[5]=='D'&&a[12]=='E')
	cout<<1;
	else if(a[5]=='C'&&a[12]=='B')
	cout<<1;
	else if(a[5]=='B'&&a[12]=='A')
	cout<<1;
	else if(a[5]=='E'&&a[12]=='D')
	cout<<1;
	else if(a[5]=='B'&&a[12]=='C')
	cout<<1;
	else if(a[5]=='A'&&a[12]=='B')
	cout<<1;
	else 
	cout<<0;
	return 0;
}
