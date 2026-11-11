#include<bits/stdc++.h>
using namespace std;
struct q{
	int sz;
	char zm;
}s[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0,y=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].sz>>s[i].zm;
	}
	int r=n-1;
	for(int i=0;i<n/2;i++)
	{
		if(s[i].zm!=s[r].zm)
		{
			x+=s[i].sz;
			y+=s[r].sz;
		}
		r--;
	}
	if(n%2==0)
	{
		if(x>y)
		{
			cout<<y;
		}
		else
		{
			cout<<x;
		}
	}
	else
	{
		if(x<y)
		{
			cout<<y;
		}
		else
		{
			cout<<x;
		}		
	}
	return 0; 
}
