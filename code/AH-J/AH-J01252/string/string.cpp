#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,num=0;
/*int hws(string s)
{
	string w;
	int f=0,i;
	for(i=0;i<=num;i++)
	{
		w[i]=s[num-i+1];
	}
	for(i=0;i<=num;i++)
	{
		if(s[i]!=w[i])
		{
			f=f+1;
		}
	}
	return f;
}*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j;
	char c;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for(j=1;j<=a;j++)
		{
			num=num+1;
			s[num]=c;
		}
	}
	string w;
	int f=0;
	for(i=0;i<=num;i++)
	{
		w[i]=s[num-i+1];
	}
	for(i=0;i<=num;i++)
	{
		if(s[i]!=w[i])
		{
			f=f+1;
		}
	}
	cout<<f/2;
	//cout<<hws(s);
	return 0;
}
