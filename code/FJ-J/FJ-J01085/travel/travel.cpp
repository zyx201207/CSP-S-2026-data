#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	int s=0,c=0,k=0;
	string a,b;
	cin>>m;
	cin>>a;
	cin>>n;
	cin>>b;
	if(m==n)
	{
		cout<<"1";
		s=1;
	}
	else
	{
		cout<<"0";
	}
	if(s==1 && a[0]==b[0] && a[1]==b[1])
	{
		cout<<"1";
		c=1;
	}
	else
	{
		cout<<"0";
	}
	if(c==1 && a[2]<='C' && a[2]>='A' && b[2]<='C' && b[2]>='A')
	{
		cout<<"1";
		k=1;
	}
	else if(c==1 && a[2]<='F' && a[2]>='D' && b[2]<='F' && b[2]>='D')
	{
		cout<<"1";
		k=2;
	}
	else
	{
		cout<<"0";
	}
	if(k==1 && (a[2]==b[2]+1 || b[2]==a[2]+1)  )
	{
		cout<<"1";
	}
	else if(k==2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}