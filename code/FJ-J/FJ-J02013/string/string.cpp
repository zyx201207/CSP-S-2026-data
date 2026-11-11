#include <iostream>
#include <string>
using namespace std;
int n;
string a,y;
int st(int cnt,string d)
{
	string b;
	for(int i=2;i<=cnt+1;i++)
	{
		b+=d[cnt-i+1];
	}
	if(d==b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x,cnt=0;
	string ans[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		ans[i]=y;
		for(int j=0;j<x;j++)
		{
			a+=y;
			cnt++;
		}
	}
	if(st(cnt,a))
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
