#include<bits/stdc++.h>
using namespace std;
long long j = 0;
long long a[200005];
string s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string l = "1";
	for(int i = 1;i <= n;i++)
	{
		char s;
		cin>>a[i];
		cin>>s;
		j += a[i];
	}
	if(j % 2 == 1)
	{
		long long d = (j+1)/2;
	}
	else
	{
		long long d = j/2;
	}
	string o = "2";
	while(true)
	{
		int h = d;
		int g = 0;
		int c = 1;
		if(h - a[c]>=0)
		{
			for(int i = g;i <= a[c];i++)
			{
				l[i] = s[c];
			}
			c++;
			h -= a[c];
			g += a[c];
		}
		else
		{
			for(int i = g;i <= d-1;i++)
			{
				l[i] = s[c];
			}
			break;
		}
	}
	cout<<0;
	return 0;
}
