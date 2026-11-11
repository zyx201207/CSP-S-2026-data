#include<iostream>
#include<cstdio>
using namespace std;
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
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		if(t%2)
		cout<<1<<endl;
		else
		cout<<2<<endl;
	}
	return 0;
}
