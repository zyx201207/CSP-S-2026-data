#include<bits/stdc++.h>
using namespace std;
struct v
{
	long long a;
	char b;
}s[200005];
string x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a;
		cin>>s[i].b;
		for(int j=1;j<=s[i].a;j++)
		{
			x+=s[i].b;
		}
	}
	int sum=0;
	for(int i=0;i<x.size()/2;i++)
	{
		if(x[i]!=x[x.size()/2-i+2])
		{
			if(s[i].a>s[x.size()/2-i+2].a)
			{
				x[x.size()/2-i+2]=x[i];
				s[i].a++;
				s[x.size()/2-i+2].a--;
			}
			else
			{
				x[i]=x[x.size()/2-i+2];
				s[x.size()/2-i+2].a++;
				s[i].a--;
			}
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
