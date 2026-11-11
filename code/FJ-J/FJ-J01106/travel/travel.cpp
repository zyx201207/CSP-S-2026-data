#include<bits/stdc++.h>
using namespace std;//Trick||Treat!
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10,x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int a)
{
	if(a<0)
	putchar('-'),a=-a;
	if(a>9)
	write(a/10);
	putchar(a%10+'0');
	return;
}
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a,b;
	bool k1,k2;
	if(s1[2]>='A'&&s1[2]<='C')
	k1=true;
	else 
	k1=false;
	
	if(s2[2]>='A'&&s2[2]<='C')
	k2=true;
	else
	k2=false;

	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<'1';
	if(a!=b)
	{
		cout<<"000"<<endl;
		return 0;
	}
	cout<<'1';
	if(k1!=k2)
	{
		cout<<"00"<<endl;
		return 0;
	}
	cout<<'1';
	if(abs(s2[2]-s1[2])==1&&!((s2[2]=='C'&&s1[2]=='D')||(s1[2]=='C'&&s2[2]=='D')))
	cout<<'1'<<endl;
	else
	cout<<'0'<<endl;
	return 0;
}
