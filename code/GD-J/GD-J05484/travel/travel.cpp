#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int p1=a2[0]-'0';
	p1*=10;
	p1+=a2[1]-'0';
	int p2=b2[0]-'0';
	p2*=10;
	p2+=b2[1]-'0';
	if(p1==p2&&a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int c1=a2[2]-'A';
	int c2=b2[2]-'A';
	if((c1<=2&&c2<=2||c1>=3&&c2>=3)&&p1==p2&&a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c1<=2&&c2<=2||c1>=3&&c2>=3)&&p1==p2&&a1==b1&&(c1+1==c2||c2+1==c1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
