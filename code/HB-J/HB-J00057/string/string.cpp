#include <iostream>
using namespace std;
long long b=0,c=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	string s,x;
	cin >> n ;
	for (int i=0;i<n;i++)
	{
		cin >> a >> x ;
		for (int j=1;j<=a;j++)
		{
			s+=x;
		}
		b+=a;
	}
	if (b%2==0)
	{
		for (int i=1;i<=b/2;i++)
		{
			if (s[b/2-1-i]!=s[b/2+i])
			{
				c++;
			}
		}
	}
	else
	{
		for (int i=1;i<=b/2;i++)
		{
			if (s[b/2-1-i]!=s[b/2+i+1])
			{
				c++;
			}
		}
	}
	cout << c ;
	return 0;
}
