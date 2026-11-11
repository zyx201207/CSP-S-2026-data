#include<bits/stdc++.h>
using namespace std;
int shao=0;
char s[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,x=0;
	char c;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> c;
		for (int j=1;j<=a;j++)
		{
			s[j]=c;
		}
		x=x+a;
	}
	if (x%2==1)
	{
		x=x+1;
		for (int i=1;i<=x/2;i++)
		{
			if (s[i-1]!=s[x-i])
			{
				shao++;
			}
		}
	}
	else
	{
		for (int i=1;i<=x/2;i++)
		{
			if (s[i-1]!=s[x-i+1])
			{
				shao++;
			}
		}	
	}
	cout << shao;
	return 0;
} 
