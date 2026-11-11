#include <bits/stdc++.h>
using namespace std;
string pd(string a,string b)
{
	int b1;
	if(a.size()>b.size())
	{
		b1=a.size()-b.size();
	}
	else
	{
		b1=b.size()-a.size();
	}
	string x;
	for(int i=1;i<=b1;i++)
	{
		x+='0';
	}
	if(a.size()<b.size())
	{
		a=x+a;
	}
	else
	{
		b=x+b;
	}
	string g;
	for(int i=0;i<=a.size()-1;i++)
	{
		if(a[i]==b[i] && a[i]=='1')
		{
			g+='1';
		}
		else
		{
			g+='0';
		}
	}
	return g;
}
string f(int a)
{
	string x,y;
	while(a)
	{
		x+=char(a%2+'0');
		a/=2;
	}
	for(int i=x.size()-1;i>=0;i--)
	{
		y+=x[i];
	}
	return y;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("ans.out","w",stdout);
	int k,s;
	cin>>k>>s;
	int a[k+1];
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+k+1,cmp);
	string p=f(a[1]);
	for(int i=2;i<=s;i++)
	{
		p=pd(p,f(a[i]));
	}
	cout<<p;
	return 0;
}
