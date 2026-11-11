#include<bits/stdc++.h>;
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,e=1,cnt=0;
	char d;
	string c;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b>>d;
		for(int i=1;i<=b;i++) 
		{
			c[e]=d;
			e++;
		}
	}
	e--;
	if(e%2==0)
	{
		for(int i=1;i<=e/2;i++)
		{
			if(c[i]!=c[e-i])
			{
				cnt++;
			}
		}
	}
	else if(e%2==1)
	{
		for(int i=1;i<=e/2;i++)
		{
			if(c[i]!=c[e-i])
			{
				cnt++;
			}
		}
	}
	cout<<cnt; 
	return 0;
}
