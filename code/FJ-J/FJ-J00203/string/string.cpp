#include <bits/stdc++.h>
using namespace std;
int n,x;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int num=1;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>c;
		while (x>0)
		{
			s[num]=c;
			num++;
			x--;
		}
	}
	num--;
	int sum=0;
	for (int i=1;i<=num/2;i++)
	{
		if (s[i]!=s[num+1-i])
		{
			s[num+1-i]==s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
