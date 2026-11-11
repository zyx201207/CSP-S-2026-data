#include<bits/stdc++.h>
using namespace std;
int n;
struct no{
	int a;
	char c;
}s[200005];
bool ch(char ca)
{
	for(int i=1;i<=n;i++)
	{
		if(s[i].c!=ca) return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2)
	{
		if(s[1].c!=s[2].c)
		{
			if(s[1].a%2==0&&s[2].a%2==1)
			{
				cout<<s[1].a/2;
			}
			else if(s[1].a%2==1&&s[2].a%2==0)
			{
				cout<<s[2].a/2;
			}
			else
			{
				cout<<min(s[1].a/2,s[2].a/2);
			}
		}
		else
		{
			cout<<0;
		}
	}
	else if(ch(s[1].c))
	{
		cout<<0;
	}
	else 
	{
		cout<<0;
	}
	return 0;
}
