#include<bits/stdc++.h>
using namespace std;
int main()
{
	///freopen("travel1.in","r",stdin); 
	///freopen("travel1.out","w",stdout); 
	int a1,b1;
	char a[3];
	char b[3];
	cin>>a1;
	for(int i=0;i<=2;i++)
	{
		cin>>a[i];
	}
	cin>>b1;
	for(int i=0;i<=2;i++)
	{
		cin>>b[i];
	}
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	else
		cout<<1;
	if(a[0]!=b[0]||a[1]!=b[1])
	{
		cout<<"000";
		return 0;
	}
	else
		cout<<1;
	if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A'||a[2]=='C'&&b[2]=='B'||a[2]=='B'&&b[2]=='C'||a[2]=='D'&&b[2]=='E'||a[2]=='E'&&b[2]=='D')
		cout<<11;
	else if(a[2]=='A'&&b[2]=='C'||a[2]=='C'&&b[2]=='A')
		cout<<10;
	else
		cout<<"00";
	return 0;
}
