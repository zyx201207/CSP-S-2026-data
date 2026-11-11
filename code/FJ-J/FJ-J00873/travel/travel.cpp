#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool fla=1; 
int zuo1,zuo2;
char b1,b2;
int zhuan(string a,int b)
{
	int x=a[0]-48,y=a[1]-48;
	x=10*x+y;
	char xx=a[2];
	if(b==1)
	{
		zuo1=x;
		b1=xx;
	}
	else
	{
		zuo2=x;
		b2=xx;	
	}
}
void jiao()
{
	if(b1<b2)
	{
		swap(b1,b2);
	}
}
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	zhuan(s1,1);
	zhuan(s2,2);
//	cout<<zuo1<<zuo2<<b1<<b2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			fla=0;
		}
	}
	if(fla) 
	{	cout<<1;
		if(zuo1==zuo2)
		{
			cout<<1;
			if(b1<='C'&&b2<='C'||(b1>='D'&&b2>='D'))
			{
				cout<<1;
				jiao();
				if(b1-1==b2)
				{
					cout<<1;
				}
				else 
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
		
	}
	else {
		cout<<"0000";
	}
	
return 0;
} 
