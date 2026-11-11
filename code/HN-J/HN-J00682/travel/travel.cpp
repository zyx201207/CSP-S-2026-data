#include<bits/stdc++.h>
using namespace std;
char s1[8];
char s2[8];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	
	cin>>c1;
	for (int i=0;i<3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for (int i=0;i<3;i++)
	{
		cin>>s2[i];
	}
	/*for(int i=0;i<3;i++)
	{
		cout<<s2[i];
	}
	cout<<' ';
	for(int i=0;i<3;i++)
	{
		cout<<s1[i];
	}*/
	//1
	if (c1==c2)
	{
		cout<<1;
		//cout<<2;
	}
	else
	{
		cout<<0;
		//cout<<2;
	}
	int a,b;
	//2
	a=s1[0]-'0';
	a*=10;
	a+=s1[1]-'0';
	b=s2[0]-'0';
	b*=10;
	b+=s2[1]-'0';
	if (a==b)
	{
		cout<<1;
		//cout<<3;
	}
	else
	{
		cout<<0;
		//cout<<3;
	}
	//3
	char c,d;
	c=s1[2];
	d=s2[2];
	if ((c=='A' || c=='B' || c=='C') && (d=='A' || d=='B' || d=='C'))
	{
		cout<<1;
		
	}
	else if ((c=='D' || c=='F') && (d=='D' || d=='F'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	//4
	if (c=='A' && d=='B' || c=='B' && d=='A' || c=='B' && d=='C' || c=='C' && d=='B' || c=='D' && d=='F' || c=='F' && d=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	
	return 0;
 } 
