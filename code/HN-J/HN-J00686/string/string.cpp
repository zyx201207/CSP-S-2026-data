#include<iostream>
using namespace std;
int n,a[20001],m=0;
char c[20001];
string s;
bool isit_string()
{
	bool fg=1;
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m-i+1])
		{
			fg=0;
			break;
		}
	}
	return fg;
}
int unstring_finder()
{
	int fg=0;
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m-i+1])
		{
			fg=i;
			break;
		}
	}
	return fg;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int mk=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		m+=a[i];
		for(int j=0;j<a[i];j++)
		{
			mk++;
			s[mk]=c[i];
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(isit_string())
		{
			cout<<sum;
			break;
		}
		if(unstring_finder()!=0)
		{
			int x=unstring_finder();
			s[x]=s[m-x+1];
			sum++;
		}
	}

	return 0;
}
